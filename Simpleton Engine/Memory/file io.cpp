//
//  file io.cpp
//  Simpleton Engine
//
//  Created by Indi Kernick on 20/4/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "file io.hpp"

Memory::FileError::FileError(const char *const what)
  : std::runtime_error(what) {}

Memory::FileHandle Memory::openFileRead(const char *const path) {
  assert(path);
  std::FILE *const file = std::fopen(path, "rb");
  if (file == nullptr) {
    throw Memory::FileError("Failed to open file for reading");
  } else {
    return {file, {}};
  }
}

Memory::FileHandle Memory::openFileWrite(const char *const path) {
  assert(path);
  std::FILE *const file = std::fopen(path, "wb");
  if (file == nullptr) {
    throw Memory::FileError("Failed to open file for writing");
  } else {
    return {file, {}};
  }
}

size_t Memory::sizeOfFile(std::FILE *const file) {
  if (std::fseek(file, 0, SEEK_END) != 0) {
    throw FileError("Failed to seek to end of file");
  }
  const long fileSize = std::ftell(file);
  if (fileSize == long(-1)) {
    throw FileError("Failed to get size of file");
  }
  std::rewind(file);
  return fileSize;
}

void Memory::readFile(void *const data, const size_t size, std::FILE *const file) {
  if (std::fread(data, size, 1, file) == 0) {
    throw FileError("Failed to read from file");
  }
}

void Memory::writeFile(void *const data, const size_t size, std::FILE *const file) {
  if (std::fwrite(data, size, 1, file) == 0) {
    throw FileError("Failed to write to file");
  }
  if (std::fflush(file) != 0) {
    throw FileError("Failed to flush file after writing");
  }
}

Memory::Buffer Memory::readFile(const std::string &path) {
  return readFile(path.c_str());
}

Memory::Buffer Memory::readFile(const char *const path) {
  return readFile(openFileRead(path).get());
}

Memory::Buffer Memory::readFile(std::FILE *const file) {
  Memory::Buffer buf(sizeOfFile(file));
  readFile(buf.data(), buf.size(), file);
  return buf;
}

Memory::Buffer Memory::readFile(std::ifstream &stream) {
  stream.seekg(0, std::ios_base::seekdir::end);
  Memory::Buffer buf(stream.tellg());
  stream.seekg(0, std::ios_base::seekdir::beg);
  stream.read(buf.data<std::ifstream::char_type>(), buf.size());
  if (stream.good()) {
    return buf;
  } else {
    throw FileError("Failed to read from input stream");
  }
}

void Memory::writeFile(const Memory::Buffer &buf, const std::string &path) {
  writeFile(buf, path.c_str());
}

void Memory::writeFile(const Memory::Buffer &buf, const char *const path) {
  writeFile(buf, openFileWrite(path).get());
}

void Memory::writeFile(const Memory::Buffer &buf, std::FILE *const file) {
  if (std::fwrite(buf.data(), buf.size(), 1, file) == 0) {
    throw FileError("Failed to write to file");
  }
  if (std::fflush(file) != 0) {
    throw FileError("Failed to flush file after writing");
  }
}

void Memory::writeFile(const Memory::Buffer &buf, std::ofstream &stream) {
  stream.write(buf.data<std::ofstream::char_type>(), buf.size<std::streamsize>());
  stream.flush();
  if (!stream.good()) {
    throw FileError("Failed to write to output stream");
  }
}
