// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#include "pch.h"

#include "AdaptiveTextRun.h"

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace ABI::AdaptiveCards::ObjectModel::WinUI3;
using namespace ABI::Windows::Foundation::Collections;

namespace AdaptiveCards::ObjectModel::WinUI3
{
    HRESULT AdaptiveTextRun::RuntimeClassInitialize() noexcept
    try
    {
        RuntimeClassInitialize(std::make_shared<TextRun>());
        return S_OK;
    }
    CATCH_RETURN;

    HRESULT AdaptiveTextRun::RuntimeClassInitialize(const std::shared_ptr<AdaptiveCards::TextRun>& sharedTextRun) noexcept
    try
    {
        m_highlight = sharedTextRun->GetHighlight();
        m_italic = sharedTextRun->GetItalic();
        m_strikethrough = sharedTextRun->GetStrikethrough();
        m_underline = sharedTextRun->GetUnderline();

        m_selectAction = GenerateActionProjection(sharedTextRun->GetSelectAction());
        RETURN_IF_FAILED(AdaptiveTextElement::InitializeTextElement(sharedTextRun));
        return S_OK;
    }
    CATCH_RETURN;

    HRESULT AdaptiveTextRun::get_Highlight(boolean* highlight)
    {
        *highlight = m_highlight;
        return S_OK;
    }

    HRESULT AdaptiveTextRun::put_Highlight(boolean highlight)
    {
        m_highlight = highlight;
        return S_OK;
    }

    HRESULT AdaptiveTextRun::get_SelectAction(_COM_Outptr_ IAdaptiveActionElement** action)
    {
        copy_to_abi(m_selectAction, action);
        return S_OK;
    }

    HRESULT AdaptiveTextRun::put_SelectAction(_In_ IAdaptiveActionElement* action)
    {
        m_selectAction = copy_from_abi<decltype(m_selectAction)>(action);
        return S_OK;
    }

    HRESULT AdaptiveTextRun::get_Italic(boolean* italic)
    {
        *italic = m_italic;
        return S_OK;
    }

    HRESULT AdaptiveTextRun::put_Italic(boolean italic)
    {
        m_italic = italic;
        return S_OK;
    }

    IFACEMETHODIMP AdaptiveTextRun::get_Strikethrough(boolean* strikethrough)
    {
        *strikethrough = m_strikethrough;
        return S_OK;
    }

    IFACEMETHODIMP AdaptiveTextRun::put_Strikethrough(boolean strikethrough)
    {
        m_strikethrough = strikethrough;
        return S_OK;
    }

    IFACEMETHODIMP AdaptiveTextRun::get_Underline(boolean* underline)
    {
        *underline = m_underline;
        return S_OK;
    }

    IFACEMETHODIMP AdaptiveTextRun::put_Underline(boolean underline)
    {
        m_underline = underline;
        return S_OK;
    }

    HRESULT AdaptiveTextRun::GetSharedModel(std::shared_ptr<AdaptiveCards::TextRun>& sharedModel) noexcept
    try
    {
        std::shared_ptr<AdaptiveCards::TextRun> textRun = std::make_shared<AdaptiveCards::TextRun>();
        RETURN_IF_FAILED(AdaptiveTextElement::CopyTextElementProperties(*textRun));

        textRun->SetItalic(m_italic);
        textRun->SetStrikethrough(m_strikethrough);
        textRun->SetHighlight(m_highlight);
        textRun->SetUnderline(m_underline);

        if (m_selectAction != nullptr)
        {
            textRun->SetSelectAction(GenerateSharedAction(m_selectAction));
        }

        sharedModel = std::move(textRun);
        return S_OK;
    }
    CATCH_RETURN;
}
