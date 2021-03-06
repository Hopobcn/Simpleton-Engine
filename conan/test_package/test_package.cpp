
//
// OBS: Only headers used in EnTT-Pacman are left uncommented
//      To be able to uncoment everything, time has to be dedicated into adding last missing conan dependencies (like sdl2_mixer)
//

//#include <Simpleton/Type List/splice.hpp>
//#include <Simpleton/Type List/reduce.hpp>
//#include <Simpleton/Type List/get.hpp>
//#include <Simpleton/Type List/type.hpp>
//#include <Simpleton/Type List/index.hpp>
//#include <Simpleton/Type List/transform.hpp>
//#include <Simpleton/Type List/pack.hpp>
//#include <Simpleton/Type List/string.hpp>
//#include <Simpleton/Type List/sort.hpp>
//#include <Simpleton/Type List/foreach.hpp>
//#include <Simpleton/Type List/concat.hpp>
//#include <Simpleton/Type List/pred.hpp>
//#include <Simpleton/Memory/alloc.hpp>
//#include <Simpleton/Memory/block allocator.hpp>
//#include <Simpleton/Memory/file io.hpp>
//#include <Simpleton/Memory/view.hpp>
//#include <Simpleton/Memory/buffer.hpp>
//#include <Simpleton/Memory/byteptr.hpp>
//#include <Simpleton/Utils/function alias.hpp>
//#include <Simpleton/Utils/hash.hpp>
//#include <Simpleton/Utils/bits.hpp>
//#include <Simpleton/Utils/generic raii.hpp>
//#include <Simpleton/Utils/smart const ref.hpp>
//#include <Simpleton/Utils/multi dim array.hpp>
//#include <Simpleton/Utils/combine hashes.hpp>
//#include <Simpleton/Utils/partial apply.hpp>
//#include <Simpleton/Utils/enum.hpp>
//#include <Simpleton/Utils/strong alias.hpp>
//#include <Simpleton/Utils/dispatcher.hpp>
//#include <Simpleton/Utils/move test.hpp>
//#include <Simpleton/Utils/tuple.hpp>
//#include <Simpleton/Utils/instance limiter.hpp>
//#include <Simpleton/Utils/console color.hpp>
//#include <Simpleton/Utils/type name.hpp>
//#include <Simpleton/Utils/safe down cast.hpp>
//#include <Simpleton/Utils/atom.hpp>
//#include <Simpleton/Utils/multi dim container.hpp>
//#include <Simpleton/Utils/member function.hpp>
//#include <Simpleton/Utils/endian.hpp>
//#include <Simpleton/Utils/numeric iterators.hpp>
//#include <Simpleton/Utils/parse string.hpp>
//#include <Simpleton/Utils/meta glm.hpp>
//#include <Simpleton/Utils/line col.hpp>
//#include <Simpleton/Utils/function traits.hpp>
//#include <Simpleton/Utils/compose string.hpp>
//#include <Simpleton/Utils/bool enable.hpp>
//#include <Simpleton/Utils/null check.hpp>
//#include <Simpleton/Utils/op stack.hpp>
//#include <Simpleton/Utils/int least.hpp>
//#include <Simpleton/Utils/profiler.hpp>
//#include <Simpleton/ECS/prototype.hpp>
//#include <Simpleton/ECS/entity id map.hpp>
//#include <Simpleton/ECS/json.hpp>
//#include <Simpleton/ECS/registry.hpp>
//#include <Simpleton/ECS/comp inits.hpp>
//#include <Simpleton/ECS/progress manager.hpp>
//#include <Simpleton/ECS/level.hpp>
//#include <Simpleton/ECS/load prototype.hpp>
//#include <Simpleton/ECS/level manager.hpp>
//#include <Simpleton/ECS/comp init.hpp>
//#include <Simpleton/Camera 2D/animate.hpp>
//#include <Simpleton/Camera 2D/matrix mul.hpp>
//#include <Simpleton/Camera 2D/rotate.hpp>
//#include <Simpleton/Camera 2D/transform.hpp>
//#include <Simpleton/Camera 2D/target.hpp>
//#include <Simpleton/Camera 2D/zoom to fit.hpp>
//#include <Simpleton/Camera 2D/constant speed.hpp>
//#include <Simpleton/Camera 2D/aabb.hpp>
//#include <Simpleton/Camera 2D/constant scale.hpp>
//#include <Simpleton/Camera 2D/props.hpp>
//#include <Simpleton/Camera 2D/camera.hpp>
//#include <Simpleton/Math/scale.hpp>
//#include <Simpleton/Math/digit stack.hpp>
//#include <Simpleton/Math/interpolate.hpp>
//#include <Simpleton/Math/rand.hpp>
//#include <Simpleton/Math/round.hpp>
//#include <Simpleton/Math/rect.hpp>
//#include <Simpleton/Math/clamp.hpp>
//#include <Simpleton/Math/point in polygon.hpp>
//#include <Simpleton/Math/pow.hpp>
//#include <Simpleton/Math/constants.hpp>
//#include <Simpleton/Math/siconstants.hpp>
//#include <Simpleton/Math/byteconstants.hpp>
//#include <Simpleton/Math/rational.hpp>
//#include <Simpleton/Math/int float.hpp>
//#include <Simpleton/Math/live stats.hpp>
//#include <Simpleton/Math/vectors.hpp>
//#include <Simpleton/Time/get.hpp>
//#include <Simpleton/Time/stopwatch.hpp>
//#include <Simpleton/Time/fps.hpp>
//#include <Simpleton/Time/simple anim.hpp>
//#include <Simpleton/Time/progress speed anim.hpp>
//#include <Simpleton/Time/anim.hpp>
//#include <Simpleton/Time/timer.hpp>
//#include <Simpleton/Time/delta.hpp>
//#include <Simpleton/Time/freq limiter.hpp>
//#include <Simpleton/Time/benchmark.hpp>
//#include <Simpleton/Time/main loop.hpp>
#include <Simpleton/Time/synchronizer.hpp>
//#include <Simpleton/Time/frame.hpp>
#include <Simpleton/SDL/quad writer.hpp>
//#include <Simpleton/SDL/surface.hpp>
//#include <Simpleton/SDL/paths.hpp>
//#include <Simpleton/SDL/mouse pos.hpp>
//#include <Simpleton/SDL/debug input.hpp>
//#include <Simpleton/SDL/renderer.hpp>
//#include <Simpleton/SDL/music.hpp>
#include <Simpleton/SDL/library.hpp>
//#include <Simpleton/SDL/audio library.hpp>
//#include <Simpleton/SDL/events.hpp>
//#include <Simpleton/SDL/error.hpp>
//#include <Simpleton/SDL/window.hpp>
//#include <Simpleton/SDL/system cursors.hpp>
//#include <Simpleton/SDL/mainloop.hpp>
#include <Simpleton/SDL/texture.hpp>
//#include <Simpleton/SDL/font library.hpp>
//#include <Simpleton/SDL/chunk.hpp>
//#include <Simpleton/Sprite/json.hpp>
#include <Simpleton/Sprite/sheet.hpp>
//#include <Simpleton/Sprite/anim.hpp>
#include <Simpleton/Sprite/id.hpp>
//#include <Simpleton/Sprite/types.hpp>
//#include <Simpleton/ID/global.hpp>
//#include <Simpleton/ID/type.hpp>
//#include <Simpleton/ID/local.hpp>
//#include <Simpleton/Application/app.hpp>
//#include <Simpleton/Application/sdl app.hpp>
//#include <Simpleton/Data/json.hpp>
//#include <Simpleton/Event/event.hpp>
//#include <Simpleton/Event/manager.hpp>
//#include <Simpleton/Graphics 2D/quad writer.hpp>
//#include <Simpleton/Graphics 2D/surface.hpp>
//#include <Simpleton/Graphics 2D/depth.hpp>
//#include <Simpleton/Graphics 2D/renderer.hpp>
//#include <Simpleton/Graphics 2D/sequence.hpp>
//#include <Simpleton/Graphics 2D/load surface.hpp>
//#include <Simpleton/Graphics 2D/geom types.hpp>
//#include <Simpleton/Graphics 2D/write surface.hpp>
//#include <Simpleton/Graphics 2D/filter surface.hpp>
//#include <Simpleton/Graphics 2D/blit surface.hpp>
//#include <Simpleton/Graphics 2D/quad writer lite.hpp>
//#include <Simpleton/Graphics 2D/render types.hpp>
//#include <Simpleton/Graphics 2D/shaders.hpp>
//#include <Simpleton/Graphics 2D/zsort.hpp>
//#include <Simpleton/Graphics 2D/types.hpp>
//#include <Simpleton/Graphics 2D/sheet tex.hpp>
//#include <Simpleton/Graphics 2D/text.hpp>
//#include <Simpleton/OpenGL/attrib pointer.hpp>
//#include <Simpleton/OpenGL/opengl.hpp>
//#include <Simpleton/OpenGL/context.hpp>
//#include <Simpleton/OpenGL/static char buffer.hpp>
//#include <Simpleton/OpenGL/vertex array.hpp>
//#include <Simpleton/OpenGL/framebuffer.hpp>
//#include <Simpleton/OpenGL/texture.hpp>
//#include <Simpleton/OpenGL/uniforms.hpp>
//#include <Simpleton/OpenGL/buffer.hpp>
//#include <Simpleton/OpenGL/shader.hpp>
//#include <Simpleton/OpenGL/type enum.hpp>
//#include <Simpleton/OpenGL/shader program.hpp>
#include <Simpleton/Grid/dir.hpp>
//#include <Simpleton/Grid/transform.hpp>
#include <Simpleton/Grid/grid.hpp>
//#include <Simpleton/Grid/a star.hpp>
#include <Simpleton/Grid/distance.hpp>
//#include <Simpleton/Grid/dir bits.hpp>
#include <Simpleton/Grid/pos.hpp>
//#include <Simpleton/Grid/dir pair.hpp>
//#include <Simpleton/Grid/morton.hpp>
//#include <Simpleton/Grid/blit.hpp>
//#include <Simpleton/Grid/one path.hpp>

#include <iostream>

int main() 
{
    std::cout << "success!" << std::endl;
    return 0;
}
