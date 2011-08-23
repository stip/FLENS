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

#ifndef FLENS_LAPACK_LAPACK_TCC
#define FLENS_LAPACK_LAPACK_TCC 1

#include <flens/lapack/aux/ilaenv.tcc>
#include <flens/lapack/aux/ilalc.tcc>
#include <flens/lapack/aux/ilalr.tcc>
#include <flens/lapack/aux/labad.tcc>
#include <flens/lapack/aux/ladiv.tcc>
#include <flens/lapack/aux/lamch.tcc>
#include <flens/lapack/aux/lapy2.tcc>
#include <flens/lapack/aux/larf.tcc>
#include <flens/lapack/aux/larfb.tcc>
#include <flens/lapack/aux/larfg.tcc>
#include <flens/lapack/aux/larft.tcc>
#include <flens/lapack/aux/lascl.tcc>
#include <flens/lapack/aux/lassq.tcc>
#include <flens/lapack/aux/laswp.tcc>
#include <flens/lapack/aux/sign.tcc>

#include <flens/lapack/eig/hd2.tcc>
#include <flens/lapack/eig/hrd.tcc>
#include <flens/lapack/eig/hseqr.tcc>
#include <flens/lapack/eig/lahr2.tcc>
#include <flens/lapack/eig/lahqr.tcc>
#include <flens/lapack/eig/lanv2.tcc>
#include <flens/lapack/eig/orghr.tcc>
#include <flens/lapack/eig/ormhr.tcc>

#include <flens/lapack/gesv/sv.tcc>
#include <flens/lapack/gesv/tf2.tcc>
#include <flens/lapack/gesv/trf.tcc>
#include <flens/lapack/gesv/trs.tcc>

#include <flens/lapack/qr/org2r.tcc>
#include <flens/lapack/qr/orgqr.tcc>
#include <flens/lapack/qr/orm2r.tcc>
#include <flens/lapack/qr/ormqr.tcc>
#include <flens/lapack/qr/qr2.tcc>
#include <flens/lapack/qr/qrf.tcc>
#include <flens/lapack/qr/qrs.tcc>

#endif // FLENS_LAPACK_LAPACK_TCC
