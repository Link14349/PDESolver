#ifndef PDE_H
#define PDE_H

#include <list>
#include <vector>
#include <functional>
#include <value.h>
#include <memory>
#include <mesh.h>

using std::shared_ptr;

template <typename ...Args>
class MeshList;


template <>
class MeshList<> {
public:
    MeshList(float w, float h, float step) { }
};

template <typename T, typename ...Args>
class MeshList<T, Args...> {
public:
    MeshList(float w, float h, float step) : value(w, h, step), next(w, h, step)
    {
//        std::cout << "--- addr:0x" << this << std::endl;
    }
    Mesh<T> value;
    MeshList<Args...> next;
};


template <typename ...Args>
class PartialList;


template <>
class PartialList<> {

};

template <typename T, typename ...Args>
class PartialList<T, Args...> {
public:
    PartialList(const std::function<T(float x, float y)>& _t, const std::function<Args(float x, float y)>&... _args) : func(_t), next(_args...)
    {
//        std::cout << "--- addr:0x" << this << std::endl;
    }
    const std::function<T(float x, float y)> func;
    PartialList<Args...> next;
};

template<typename ...Args>
class PDE
{
public:
    PDE(const MeshList<Args...>& meshlist, const PartialList<Args...>& partialList) : meshes(meshlist), partials(partialList) {

    }
private:
    const MeshList<Args...>& meshes;
    const PartialList<Args...>& partials;
};

#endif // PDE_H
