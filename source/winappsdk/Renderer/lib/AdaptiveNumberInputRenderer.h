// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

namespace AdaptiveCards::Rendering::WinAppSDK
{
    class AdaptiveNumberInputRenderer
        : public Microsoft::WRL::RuntimeClass<Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::WinRtClassicComMix>,
                                              ABI::AdaptiveCards::Rendering::WinAppSDK::IAdaptiveElementRenderer>
    {
        AdaptiveRuntime(AdaptiveNumberInputRenderer);

    public:
        HRESULT RuntimeClassInitialize() noexcept;

        IFACEMETHODIMP Render(_In_ ABI::AdaptiveCards::ObjectModel::WinAppSDK::IAdaptiveCardElement* cardElement,
                              _In_ ABI::AdaptiveCards::Rendering::WinAppSDK::IAdaptiveRenderContext* renderContext,
                              _In_ ABI::AdaptiveCards::Rendering::WinAppSDK::IAdaptiveRenderArgs* renderArgs,
                              _COM_Outptr_ ABI::Windows::UI::Xaml::IUIElement** result) noexcept override;
    };

    ActivatableClass(AdaptiveNumberInputRenderer);
}