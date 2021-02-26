#ifndef MESH_H
#define MESH_H

#include <iostream>
#include <memory>
using std::shared_ptr;
using std::make_shared;

template <class T>
class Mesh
{
public:
    Mesh(float _w, float _h, float _step)
        : w(_w), h(_h), step(_step), ivStep(1 / _step), hIvStep(.5f * ivStep), iw((int)(w * ivStep)), ih((int)(h * ivStep)) {
        mesh = new T*[iw + 1];
        for (int i = 0; i <= iw; i++)
            mesh[i] = new T[ih + 1];
    }
    void fill(std::function<T(float x, float y)> f) {
        for (int i = 0; i <= iw; i++) {
            for (int j = 0; j <= ih; j++) {
                mesh[i][j] = f(i * step, j * step);
            }
        }
    }
    T& operator()(float x, float y) {
        return mesh[ix(x)][ix(y)];
    }
#define MESH_CHECK_BOUND if (ifx < 0 || ifx >= iw || ifx < 0 || ify >= ih) { std::cout << "Warn: Index out of bounds at mesh.h:" << __LINE__ << std::endl; std::cout.flush(); return T(); }
    T partial_x(std::function<T(float x, float y)> f, float x, float y) {
        int ifx(ix(x)), ify(ix(y));
        MESH_CHECK_BOUND
        if (ifx == 0) return (f(step, y) - f(0, y)) * ivStep;
        if (ifx == iw - 1) return (f(w - step, y) - f(w - 2 * step, y)) * ivStep;
        return (f(x + step, y) - f(x - step, y)) * hIvStep;
    }
    T partial_y(std::function<T(float x, float y)> f, float x, float y) {
        int ifx(ix(x)), ify(ix(y));
        MESH_CHECK_BOUND
        if (ifx == 0) return (f(step, y) - f(0, y)) * ivStep;
        if (ifx == iw - 1) return (f(w - step, y) - f(w - 2 * step, y)) * ivStep;
        return (f(x + step, y) - f(x - step, y)) * hIvStep;
    }
    T partial_x(float x, float y) {
        int ifx(ix(x)), ify(ix(y));
        MESH_CHECK_BOUND
        if (ifx == 0) return (mesh[1][ify] - mesh[0][ify]) * ivStep;
        if (ifx == iw - 1) return (mesh[iw - 1][ify] - mesh[iw - 2][ify]) * ivStep;
        return (mesh[ifx + 1][ify] - mesh[ifx - 1][ify]) * hIvStep;
    }
    T partial_y(float x, float y) {
        int ifx(ix(x)), ify(ix(y));
        MESH_CHECK_BOUND
        if (ify == 0) return (mesh[ifx][1] - mesh[ifx][0]) * ivStep;
        if (ify == ih - 1) return (mesh[ifx][ih - 1] - mesh[ifx][ih - 2]) * ivStep;
        return (mesh[ifx][ify + 1] - mesh[ifx][ify - 1]) * hIvStep;
    }
    ~Mesh() {
        for (int i = 0; i <= iw; i++) {
            delete[] mesh[i];
        }
        delete[] mesh;
    }
protected:
    T** mesh;
    float w, h, step, ivStep, hIvStep;// ivStep: step的倒数, hIvStep: 0.5ivStep
    int iw, ih;
    inline int ix(float fx) {
        return (int)(fx * ivStep);
    }
};


#endif // MESH_H
