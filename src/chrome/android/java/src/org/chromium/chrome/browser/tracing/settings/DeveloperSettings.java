// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

package org.chromium.chrome.browser.tracing.settings;

import android.os.Bundle;
import android.support.v7.preference.PreferenceFragmentCompat;

import org.chromium.chrome.R;
import org.chromium.chrome.browser.ChromeVersionInfo;
import org.chromium.chrome.browser.preferences.ChromePreferenceKeys;
import org.chromium.chrome.browser.preferences.SharedPreferencesManager;
import org.chromium.chrome.browser.settings.SettingsUtils;
import org.chromium.components.version_info.Channel;
import org.chromium.components.version_info.VersionConstants;

/**
 * Settings fragment containing preferences aimed at Chrome and web developers.
 */
public class DeveloperSettings extends PreferenceFragmentCompat {
    private static final String UI_PREF_BETA_STABLE_HINT = "beta_stable_hint";

    // Non-translated strings:
    private static final String MSG_DEVELOPER_OPTIONS_TITLE = "Developer options";

    public static boolean shouldShowDeveloperSettings() {
        // Always enabled on canary, dev and local builds, otherwise can be enabled by tapping the
        // Chrome version in Settings>About multiple times.
        if (VersionConstants.CHANNEL <= Channel.DEV) return true;
        return SharedPreferencesManager.getInstance().readBoolean(
                ChromePreferenceKeys.SETTINGS_DEVELOPER_ENABLED, false);
    }

    public static void setDeveloperSettingsEnabled() {
        SharedPreferencesManager.getInstance().writeBoolean(
                ChromePreferenceKeys.SETTINGS_DEVELOPER_ENABLED, true);
    }

    @Override
    public void onCreatePreferences(Bundle savedInstanceState, String s) {
        getActivity().setTitle(MSG_DEVELOPER_OPTIONS_TITLE);
        SettingsUtils.addPreferencesFromResource(this, R.xml.developer_preferences);

        if (ChromeVersionInfo.isBetaBuild() || ChromeVersionInfo.isStableBuild()) {
            getPreferenceScreen().removePreference(findPreference(UI_PREF_BETA_STABLE_HINT));
        }
    }
}
