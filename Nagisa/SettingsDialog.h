﻿/*
 * PROJECT:   Nagisa
 * FILE:      SettingsDialog.h
 * PURPOSE:   Definition for the Settings Dialog.
 *
 * LICENSE:   The MIT License
 *
 * DEVELOPER: Mouri_Naruto (Mouri_Naruto AT Outlook.com)
 */

#pragma once

#include "SettingsDialog.g.h"

namespace winrt::Nagisa::implementation
{
    using Assassin::TransferManager;
    using Windows::Storage::IStorageFolder;
    using Windows::UI::Xaml::Controls::CheckBox;
    using Windows::UI::Xaml::Controls::ContentDialog;
    using Windows::UI::Xaml::Controls::ContentDialogButtonClickEventArgs;
    using Windows::UI::Xaml::RoutedEventArgs;

    struct SettingsDialog : SettingsDialogT<SettingsDialog>
    {
    private:
        TransferManager m_TransferManager = nullptr;
        IStorageFolder m_LastusedFolder = nullptr;

    public:
        SettingsDialog(
            TransferManager const& TransferManager);

        fire_and_forget ContentDialog_Loaded(
            IInspectable const& sender,
            RoutedEventArgs const& e);
        fire_and_forget CustomDownloadFolderBrowseButton_Click(
            IInspectable const& sender,
            RoutedEventArgs const& e);
        void UseCustomFolder_Click(
            IInspectable const& sender,
            RoutedEventArgs const& e);
    };
}

namespace winrt::Nagisa::factory_implementation
{
    struct SettingsDialog :
        SettingsDialogT<SettingsDialog, implementation::SettingsDialog>
    {
    };
}
