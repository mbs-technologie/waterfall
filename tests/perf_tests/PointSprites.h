//
// Copyright (c) 2014 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

#include "SimpleBenchmark.h"

struct PointSpritesParams : public BenchmarkParams
{
    unsigned int iterations;
    unsigned int count;
    float size;
    unsigned int numVaryings;

    virtual std::string name() const;
};

class PointSpritesBenchmark : public SimpleBenchmark
{
public:
    PointSpritesBenchmark(const PointSpritesParams &params);

    virtual bool initializeBenchmark();
    virtual void destroyBenchmark();
    virtual void beginDrawBenchmark();
    virtual void drawBenchmark();

private:
    DISALLOW_COPY_AND_ASSIGN(PointSpritesBenchmark);

    GLuint mProgram;
    GLuint mBuffer;

    const PointSpritesParams mParams;
};