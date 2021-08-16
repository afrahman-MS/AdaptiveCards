// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

namespace AdaptiveCards::Rendering::WinAppSDK
{
    class AdaptiveShowCardActionConfig
        : public Microsoft::WRL::RuntimeClass<Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::WinRtClassicComMix>,
                                              ABI::AdaptiveCards::Rendering::WinAppSDK::IAdaptiveShowCardActionConfig>
    {
        AdaptiveRuntime(AdaptiveShowCardActionConfig);

    public:
        HRESULT RuntimeClassInitialize() noexcept;
        HRESULT RuntimeClassInitialize(AdaptiveCards::ShowCardActionConfig showCardActionConfig) noexcept;

        IFACEMETHODIMP get_ActionMode(_Out_ ABI::AdaptiveCards::Rendering::WinAppSDK::ActionMode* value);
        IFACEMETHODIMP put_ActionMode(ABI::AdaptiveCards::Rendering::WinAppSDK::ActionMode value);

        IFACEMETHODIMP get_Style(_Out_ ABI::AdaptiveCards::ObjectModel::WinAppSDK::ContainerStyle* style);
        IFACEMETHODIMP put_Style(ABI::AdaptiveCards::ObjectModel::WinAppSDK::ContainerStyle style);

        IFACEMETHODIMP get_InlineTopMargin(_Out_ UINT32* value);
        IFACEMETHODIMP put_InlineTopMargin(UINT32 value);

    private:
        ABI::AdaptiveCards::Rendering::WinAppSDK::ActionMode m_actionMode;
        ABI::AdaptiveCards::ObjectModel::WinAppSDK::ContainerStyle m_containerStyle;
        UINT32 m_inlineTopMargin;
    };

    ActivatableClass(AdaptiveShowCardActionConfig);
}