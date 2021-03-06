// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// #import {isChromeOS} from 'chrome://resources/js/cr.m.js';
// #import {TestBrowserProxy} from 'chrome://test/test_browser_proxy.m.js';

cr.define('settings', function() {
  /**
   * A test version of LifetimeBrowserProxy.
   *
   * @implements {settings.LifetimeBrowserProxy}
   */
  /* #export */ class TestLifetimeBrowserProxy extends TestBrowserProxy {
    constructor() {
      const methodNames = ['restart', 'relaunch'];
      if (cr.isChromeOS) {
        methodNames.push('signOutAndRestart', 'factoryReset');
      }

      super(methodNames);
    }

    /** @override */
    restart() {
      this.methodCalled('restart');
    }

    /** @override */
    relaunch() {
      this.methodCalled('relaunch');
    }
  }

  if (cr.isChromeOS) {
    /** @override */
    TestLifetimeBrowserProxy.prototype.signOutAndRestart = function() {
      this.methodCalled('signOutAndRestart');
    };

    /** @override */
    TestLifetimeBrowserProxy.prototype.factoryReset = function(
        requestTpmFirmwareUpdate) {
      this.methodCalled('factoryReset', requestTpmFirmwareUpdate);
    };
  }

  // #cr_define_end
  return {
    TestLifetimeBrowserProxy: TestLifetimeBrowserProxy,
  };
});
