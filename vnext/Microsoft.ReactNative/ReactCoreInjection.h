// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#pragma once

#include "ReactCoreInjection.g.h"
#include "ReactViewOptions.g.h"

#include "INativeUIManager.h"
#include "React.h"
#include "ReactHost/React.h"
#include "ReactPropertyBag.h"
#include "winrt/Microsoft.ReactNative.h"

namespace winrt::Microsoft::ReactNative::implementation {

struct ReactViewOptions : ReactViewOptionsT<ReactViewOptions> {
  ReactViewOptions() noexcept;

  winrt::hstring ComponentName() noexcept;
  void ComponentName(winrt::hstring value) noexcept;

  JSValueArgWriter InitialProps() noexcept;
  void InitialProps(JSValueArgWriter value) noexcept;

  Mso::React::ReactViewOptions CreateViewOptions() noexcept;

 private:
  winrt::hstring m_componentName;
  JSValueArgWriter m_initialProps;
};

struct ReactCoreInjection : ReactCoreInjectionT<ReactCoreInjection> {
  ReactCoreInjection() noexcept;
  static ReactPropertyId<UIBatchCompleteCallback> UIBatchCompleteCallbackProperty() noexcept;
  static ReactPropertyId<winrt::Microsoft::ReactNative::ReactNonAbiValue<
      std::function<void(ReactNative::ReactDispatcherCallback const &)>>>
  PostToUIBatchingQueueProperty() noexcept;
  static void SetUIBatchCompleteCallback(
      IReactPropertyBag const &properties,
      UIBatchCompleteCallback const &callback) noexcept;

  static IReactViewHost MakeViewHost(
      ReactNative::ReactNativeHost host,
      ReactNative::ReactViewOptions viewOptions) noexcept;
  static void PostToUIBatchingQueue(
      ReactNative::IReactContext context,
      ReactNative::ReactDispatcherCallback callback) noexcept;

  static void SetPlatformNameOverride(IReactPropertyBag const &properties, winrt::hstring const &platformName) noexcept;
  static std::string GetPlatformName(IReactPropertyBag const &properties) noexcept;

  static uint64_t GetTopLevelWindowId(const IReactPropertyBag &properties) noexcept;
  static void SetTopLevelWindowId(const IReactPropertyBag &properties, uint64_t windowId) noexcept;

  static TimerFactory GetTimerFactory(const IReactPropertyBag &properties) noexcept;
  static void SetTimerFactory(const IReactPropertyBag &properties, const TimerFactory &timerFactory) noexcept;
};

struct ReactViewHost : public winrt::implements<ReactViewHost, IReactViewHost> {
  ReactViewHost(
      const winrt::Microsoft::ReactNative::ReactNativeHost &host,
      Mso::React::IReactViewHost &viewHost,
      const winrt::Microsoft::ReactNative::IReactDispatcher &uiDispatcher);

  winrt::Windows::Foundation::IAsyncAction ReloadViewInstance() noexcept;
  winrt::Windows::Foundation::IAsyncAction ReloadViewInstanceWithOptions(
      ReactNative::ReactViewOptions options) noexcept;
  winrt::Windows::Foundation::IAsyncAction UnloadViewInstance() noexcept;
  winrt::Windows::Foundation::IAsyncAction AttachViewInstance(IReactViewInstance viewInstance) noexcept;
  winrt::Windows::Foundation::IAsyncAction DetachViewInstance() noexcept;
  winrt::Microsoft::ReactNative::ReactNativeHost ReactNativeHost() noexcept;

 private:
  const ReactNative::ReactNativeHost m_host;
  Mso::CntPtr<Mso::React::IReactViewHost> m_viewHost;
  winrt::Microsoft::ReactNative::IReactDispatcher m_uiDispatcher;
};

} // namespace winrt::Microsoft::ReactNative::implementation

namespace winrt::Microsoft::ReactNative::factory_implementation {
struct ReactCoreInjection : ReactCoreInjectionT<ReactCoreInjection, implementation::ReactCoreInjection> {};
struct ReactViewOptions : ReactViewOptionsT<ReactViewOptions, implementation::ReactViewOptions> {};
} // namespace winrt::Microsoft::ReactNative::factory_implementation
