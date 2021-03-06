#include <cmath>
#include <stdlib.h>
#include <assert.h>

#include "ys_matrix.h"

double ran_uniform() {
    return rand()/((double)RAND_MAX + 1);
}

using namespace ys;

int main(void) {
    DMatrix<double> dmatrix(100, 1000);
    for (int i = 0; i < dmatrix.getDimX(); ++i) {
    for (int j = 0; j < dmatrix.getDimY(); ++j) {
        dmatrix(i, j) = ran_uniform();
    }
    }
    assert (dmatrix.getDimX() == 100);
    assert (dmatrix.getDimY() == 1000);
    dmatrix.save("tmpfile");
    DMatrix<double> dmatrix1;
    dmatrix1.load("tmpfile");
    assert (dmatrix1.getDimX() == 100);
    assert (dmatrix1.getDimY() == 1000);
    for (int i = 0; i < dmatrix1.getDimX(); ++i) {
    for (int j = 0; j < dmatrix1.getDimY(); ++j) {
        assert (dmatrix1[i][j] = dmatrix[i][j]);
    }
    }

    DMatrix<double> dmatrix2;
    dmatrix2 = dmatrix;
    assert (dmatrix2.getDimX() == 100);
    assert (dmatrix2.getDimY() == 1000);
    for (int i = 0; i < dmatrix2.getDimX(); ++i) {
    for (int j = 0; j < dmatrix2.getDimY(); ++j) {
        assert (dmatrix1[i][j] = dmatrix2[i][j]);
    }
    }

    DMatrix<double> dmatrix3;
    dmatrix3.assign(dmatrix1);
    assert (dmatrix3.getDimX() == 100);
    assert (dmatrix3.getDimY() == 1000);
    for (int i = 0; i < dmatrix3.getDimX(); ++i) {
    for (int j = 0; j < dmatrix3.getDimY(); ++j) {
        assert (dmatrix3[i][j] = dmatrix2[i][j]);
    }
    }

    DMatrix<double> dmatrix4(dmatrix2);
    assert (dmatrix4.getDimX() == 100);
    assert (dmatrix4.getDimY() == 1000);
    for (int i = 0; i < dmatrix4.getDimX(); ++i) {
    for (int j = 0; j < dmatrix4.getDimY(); ++j) {
        assert (dmatrix4[i][j] = dmatrix[i][j]);
    }
    }
    return 0;
}
