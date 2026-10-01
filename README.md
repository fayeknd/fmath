# FayeMath

Can't be bothered writing a readme rn tbh!

## Installation: 
literally just drop "fm" into your include or external or wherever and done.

## Usage:
namespace is fm, vectors can be initialised with just vec() for any size.
for instance, fm::vec(1.0f, 0.0f, 1.0f) will return an fm::vec3<float>(), fm::vec(2, 0) will return an fm::vec2<int>.
fm::vec2, 3, 4, and just fm::vec can be specified to any type, but there is no guarantee that various functions will work on that type.
fm::mat4 is much the same. 
fm::mat4 includes functions such as model, (which takes a position, rotation, scale and skew) perspective, orthographic, and general individual translations like mat.translate, mat.skew, mat.rotate, mat.scale.
matrices can be directly changed or just return a changed matrix. for example:

mat.translated({1, 1, 0}) just returns "mat" translated up by 1 unit and right by 1 unit, but does not actually perform the translation on the matrix.
mat.translate({1, 1, 0}) returns the same matrix, but also translates the original matrix along the way.