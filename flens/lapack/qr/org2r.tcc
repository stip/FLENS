/*
 *   Copyright (c) 2011, Michael Lehn
 *
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *   1) Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *   2) Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in
 *      the documentation and/or other materials provided with the
 *      distribution.
 *   3) Neither the name of the FLENS development group nor the names of
 *      its contributors may be used to endorse or promote products derived
 *      from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* Based on
      SUBROUTINE DORG2R( M, N, K, A, LDA, TAU, WORK, INFO )
 *
 *  -- LAPACK routine (version 3.2) --
 *  -- LAPACK is a software package provided by Univ. of Tennessee,    --
 *  -- Univ. of California Berkeley, Univ. of Colorado Denver and NAG Ltd..--
 *     November 2006
 */

#ifndef FLENS_LAPACK_QR_ORG2R_TCC
#define FLENS_LAPACK_QR_ORG2R_TCC 1

#include <flens/blas/blas.h>
#include <flens/lapack/lapack.h>

namespace flens { namespace lapack {

//-- forwarding ----------------------------------------------------------------
template <typename IndexType, typename MA, typename VTAU, typename VWORK>
void
org2r(IndexType k, MA &&A, const VTAU &tau, VWORK &&work)
{
    org2r(k, A, tau, work);
}

//-- org2r ---------------------------------------------------------------------
template <typename IndexType, typename MA, typename VTAU, typename VWORK>
void
org2r(IndexType k, GeMatrix<MA> &A, const DenseVector<VTAU> &tau,
      DenseVector<VWORK> &work)
{
    ASSERT(A.firstRow()==IndexType(1));
    ASSERT(A.firstCol()==IndexType(1));
    ASSERT(tau.firstIndex()==IndexType(1));
    ASSERT(work.length()>=A.numCols());

    typedef typename GeMatrix<MA>::ElementType  T;

    const Underscore<IndexType> _;

    IndexType m = A.numRows();
    IndexType n = A.numCols();

    ASSERT(n<=m);
    ASSERT(k<=n);
    ASSERT(0<=k);

//
//  Quick return if possible
//
    if (n<=0) {
        return;
    }
//
//  Initialise columns k+1:n to columns of the unit matrix
//
    for (IndexType j=k+1; j<=n; ++j) {
        for (IndexType l=1; l<=m; ++l) {
            A(l,j) = 0;
        }
        A(j,j) = 1;
    }

    for (IndexType i=k; i>=1; --i) {
//
//      Apply H(i) to A(i:m,i+1:n) from the left
//
        if (i<n) {
            A(i,i) = 1;
            larf(Left, A(_(i,m),i), tau(i), A(_(i,m),_(i+1,n)), work);
        }
        if (i<m) {
            blas::scal(-tau(i), A(_(i+1,m),i));
        }
        A(i,i) = T(1) - tau(i);
//
//      Set A(1:i-1,i) to zero
//
        for (IndexType l=1; l<i; ++l) {
            A(l,i) = 0;
        }
    }
}

} } // namespace lapack, flens

#endif // FLENS_LAPACK_QR_ORG2R_TCC