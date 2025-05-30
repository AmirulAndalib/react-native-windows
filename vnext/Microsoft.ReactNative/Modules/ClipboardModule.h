// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
#pragma once

#include "codegen/NativeClipboardSpec.g.h"
#include <NativeModules.h>

namespace Microsoft::ReactNative {

REACT_MODULE(Clipboard)
struct Clipboard {
  using ModuleSpec = ReactNativeSpecs::ClipboardSpec;

  REACT_INIT(Initialize)
  void Initialize(winrt::Microsoft::ReactNative::ReactContext const &reactContext) noexcept;

  REACT_METHOD(getString)
  void getString(winrt::Microsoft::ReactNative::ReactPromise<std::string> result) noexcept;

  REACT_METHOD(setString)
  void setString(winrt::hstring content) noexcept;

  winrt::Microsoft::ReactNative::ReactContext m_reactContext;
};

} // namespace Microsoft::ReactNative
