// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "escher/gl/unique_texture.h"

#include "escher/base/macros.h"

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <utility>

namespace escher {

UniqueTexture::UniqueTexture() {
}

UniqueTexture::~UniqueTexture() {
  Reset();
}

void UniqueTexture::Generate() {
  Reset();
  glGenTextures(1, &id_);
}

void UniqueTexture::Reset() {
  if (id_) {
    GLuint id = id_;
    id_ = 0;
    glDeleteTextures(1, &id);
  }
}

UniqueTexture::UniqueTexture(UniqueTexture&& other) : id_(other.id_) {
  other.id_ = 0;
}

UniqueTexture& UniqueTexture::operator=(UniqueTexture&& other) {
  std::swap(id_, other.id_);
  return *this;
}

}  // namespace escher