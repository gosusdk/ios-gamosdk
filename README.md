# IOS GinSDK
## [2.0.3]

### 🐛 Bug Fixes

#### OpenGameLog API Integration
- **OpenGameLog on SDK Init**: Added automatic OpenGameLog API call when SDK initialization succeeds

#### Logout API Request
- **ClientID Missing in Logout Request**: Fixed logout API request not including ClientID parameter
  - **Issue**: Logout API calls were missing the ClientID value, causing potential authentication issues

### 🔧 Improvements

#### Logging & Debugging
- **Enhanced OpenGameLog Logging**: Improved log messages to distinguish between parameterized and parameterless OpenGameLog calls
  - Changed log message from "idAppTrackingOpen" to "idAppTrackingOpen with multi params" for clarity
  - Separate log message for parameterless version
- **Logout Response Handling**: Added comprehensive response callback for logout operations with success/failure status


> **⚠️ BREAKING CHANGES in v2.0.1**: Airbrigde Tracking module had removed.

[![Platforms](https://img.shields.io/cocoapods/p/FBSDKCoreKit.svg)]()

> **⚠️ BREAKING CHANGES in v2.0.0**: The `loginSuccess` delegate method signature has changed. Please see the [Migration Guide](#initialize-sdk-delegate) below for updated implementation.

**This guide shows you how to integrate your iOS app using the GinSDK for iOS. The GinSDK for iOS consists of the following component SDKs:**
  - The GinSDK Core
  - Third-party framework: 
      - GoogleSigin SDK, Firebase SDK, Facebook SDK, AppsFlyer SDK
      - Grpc Framework (GRPCClient, ProtoBuf, ProtoRPC, RxLibrary, ...)
      - Download at : (https://drive.google.com/file/d/1tRDH7nnd4pcozV_b1BVCOdEH8LBYDnHd/view?usp=sharing)
  - Ios version support: 13+
  
### FEATURES:
  - Login: Authenticate people with their my server ID, Google and Facebook credentials.
  - Payment IAP: Pay to buy products from in-app
  - Track Events: Track events with third parties including Appsflyer and Firebase tracking
  - **Modular SDK Initialization (New in v2.0.2)**: Enhanced SDK initialization with configurable tracking modules
    - Individual module control: Enable/disable AppsFlyer, Firebase, and ITS tracking
    - Performance optimization: Only load enabled modules
    - Backward compatibility: Traditional initialization still supported
  - **Enhanced Privacy Compliance**: App Store privacy manifest and enhanced data protection
  - You will need some included keys: GameClientID, GameSDKSignature, GoogleAppID, FacebookAppID, FacebookClientToken, AppsFlyerDevKey and GoogleService-Info.plist file

# Try It Out

**Download the official version: [click here](https://github.com/gosusdk/ios-gamosdk/releases)**
* GoogleService-Info.plist: send via mail
* Install the following: App Tracking Transparency framework only available starting from Xcode 12 or later-The SDK supports iOS11+

# Integrate

- Embed GinSDK latest version and Third party framework into your project
- Some other libraries: 
  - AuthenticationServices.framework
  - MediaPlayer.framework
  - MobileCoreServices.framework
  - SystemConfiguration.framework
  - MessageUI.framework
  - Accelerate.framework
  - **AdSupport.framework**
  - **AppTrackingTransparency.framework**
  - **AdServices.framework**
  - **StoreKit.framework**
  - **iAd.framework**
- Adding Capabilities: Sign-in with Apple, Push Notifications

### With Facebook IOS SDK version 13 or latest
  - Create a swift file (arbitrary name), confirm "Create Bridging Header" when prompt appear
  - Enable Modules (C and Objective-C) set to YES: Target --> Build Settings --> Enable Modules (C and Objective-C)

### GRPC Framework Embed
  ![image](https://user-images.githubusercontent.com/94542020/160530360-23295245-4eb7-4f0b-b04b-cbcfee270a7e.png)

# Configuration
- Insert -ObjC -lc++ -lz to “Other Linker Flags ”on Xcode Project: Main target -> build settings -> search "other linker flags"
- Configure Tracking Usage Description into .plist file (default: info.plist)*.
  Open with source and insert code: 
  ```xml
  <key>NSUserTrackingUsageDescription</key>
  <string>This identifier will be used to deliver personalized ads to you.</string>
  ```
- Configure ServerInfo into .plist file (default: info.plist)*. IN the <string> tag, key ServerInfo will be provided privately via email
```xml
<key>ServerAddress</key>
<string>server_address_value</string>
<key>ServerPort</key>
<string>server_port_value</string>
<key>NegotiationType</key>
<string>negotiation_type_value</string>
```
- Configure GameClientID into .plist file (default: info.plist)*. IN the <string> tag, key GameClientID will be provided privately via email
```xml
<key>GameClientID</key>
<string>GameClientID</string>
```

- Configure GameSdkSignature into .plist file (default: info.plist)*. IN the <string> tag, key GameSdkSignature will be provided privately via email
```xml
<key>GameSdkSignature</key>
<string>GameSDKSignature</string>
```
### Configure GoogleSignIn in your project (default info.plist)
  ** Refer [Get started with Google Sign-In for iOS](https://developers.google.com/identity/sign-in/ios/start-integrating) **
  ```xml
   <key>GIDClientID</key>
   <string>1234567890-abcdefg.apps.googleusercontent.com</string>
   <key>CFBundleURLTypes</key>
   <array>
    <dict>
       <key>CFBundleURLSchemes</key>
       <array>
          <string>com.googleusercontent.apps.1234567890-abcdefg</string>
       </array>
    </dict>
   </array>
  ```
### Configure FacebookSDK in your project (default info.plist)
** Refer [Facebook get started](https://developers.facebook.com/docs/ios/getting-started#step-2---configure-your-project) **
```xml
<key>FacebookAppID</key>
<string>FacebookAppID</string>
<key>FacebookClientToken</key>
<string>CLIENT-TOKEN</string>
<key>FacebookDisplayName</key>
<string>FacebookDisplayName</string>
<key>CFBundleURLTypes</key>
<array>
  <dict>
    <key>CFBundleURLSchemes</key>
    <array>
      <string>fbFacebookAppID</string>
    </array>
  </dict>
</array>
<key>LSApplicationQueriesSchemes</key>
<array>
  <string>fbapi</string>
  <string>fbapi20130214</string>
  <string>fbapi20130410</string>
  <string>fbapi20130702</string>
  <string>fbapi20131010</string>
  <string>fbapi20131219</string>
  <string>fbapi20140410</string>
  <string>fbapi20140116</string>
  <string>fbapi20150313</string>
  <string>fbapi20150629</string>
  <string>fbapi20160328</string>
  <string>fbauth</string>
  <string>fb-messenger-share-api</string>
  <string>fbauth2</string>
  <string>fbshareextension</string>
</array>
```
* Replace APP-ID with FacebookApp ID
* In the key FacebookClientToken, replace CLIENT-TOKEN 
* In the key FacebookDisplayName, replaceAPP-NAME with the name of provided.

* NOTE: Just use 1 CFBundleURLSchemes key for both GoogleSignIn and FacebookSignIn URLs.
```xml
<key>CFBundleURLTypes</key>
<array>
    <dict>
        <key>CFBundleURLSchemes</key>
        <array>
            <string>fbFacebookAppID</string>
            <string>com.googleusercontent.apps.1234567890-abcdefg</string>
        </array>
    </dict>
</array>
```

### Configure ItsSDK in your project (default info.plist)
- Configure ItsSDK module tracking into .plist file (default: info.plist)*. IN the <string> tag, keys config will be provided privately via email
  ```xml
	  <key>ItsMode</key>
	  <string>TEST</string>
	  <key>ItsSigningKey</key>
	  <string>sample_value</string>
	  <key>ItsWriteKey</key>
	  <string>sample_value</string>
  ```

### Configure AppsFlyer in your project (default info.plist)
- Configure AppsFlyer module tracking into .plist file (default: info.plist)*. Keys config will be provided privately via email
  ```xml
	  <key>AppsflyerAppleID</key>
	  <string>YOUR_APPLE_APP_ID</string>
  ```

### Add a Bridging Header file if your project does not use Swift.
- Xcode -> New -> File from Template... -> Header File -> Done

### If your project uses SignIn with AppleID, add the following key-value pairs to your .entitlements file.
```xml
    <key>com.apple.developer.applesignin</key>
    <array>
        <string>Default</string>
    </array>
```

### Add services and SDK related resource library
1. The file Appdelegate.m configuration instructions are as follows:
```objectivec
#import "GinSDK.h"
#import <UserNotifications/UserNotifications.h>
@interfaceAppDelegate()<FIRMessagingDelegate, UNUserNotificationCenterDelegate>
@end
```
2. Add openURL
```objectivec
- (BOOL)application:(UIApplication *)application
            openURL:(NSURL *)url
            options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options {
    if (@available(iOS 9.0, *)) {
        BOOL handled = [[GinSDK sharedInstance] application:application openURL:url options:options];
        return handled;
    } else {
        return YES;
    }
}
```
3. Add didFinishLaunchingWithOption
```objectivec
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    //your code
    
    //GinSDK
    [[GinSDK sharedInstance] initSdk:^(NSString *initStatus) {
        NSLog(@"initStatus = %@", initStatus);
        if ([initStatus isEqual:@"success"]) {
            NSLog(@"Gin init ok");
        } else {
            NSLog(@"Gin init failed");
        }
    }];
    [[GinSDK sharedInstance] applicationDelegate:self andApplication:application didFinishLaunchingWithOptions:launchOptions];
    return YES;
}
```
4. Add applicationDidBecomeActive
```objectivec
- (void)applicationDidBecomeActive:(UIApplication *)application {
    NSLog(@"applicationDidBecomeActive");
    [[GinSDK sharedInstance] applicationDidBecomeActive:application];
    application.applicationIconBadgeNumber = 0;
}
```
5. Add applicationWillTerminate
```objectivec
- (void)applicationWillTerminate:(UIApplication *)application {
    //reset owner billing had payment
    [[GinSDK AppleIAP] terminateIAP];
}
```
6. Registration FCM token and message
```objectivec
- (void)messaging:(FIRMessaging *)messaging didReceiveRegistrationToken:(NSString *)fcmToken {
    [[GinSDK Firebase] messaging:messaging didReceiveRegistrationToken:fcmToken];
}
- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error {
    NSLog(@"APNs Unable to register for remote notifications: %@", error);
}
- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
  [[GinSDK sharedInstance] application:application didRegisterForRemoteNotificationsWithDeviceToken:deviceToken];
    NSLog(@"APNs device token retrieved: %@", deviceToken);
    [[GinSDK sharedInstance] application:application didRegisterForRemoteNotificationsWithDeviceToken:deviceToken];
    //tracking uninstall
    [[GinSDK GTracking] registerForRemoteNotifications:deviceToken];
}
- (void)application:(UIApplication *)application 
        didReceiveRemoteNotification:(NSDictionary *) userInfo {
    NSLog(@"APNs full message. %@", userInfo);
}
- (void)application:(UIApplication *)application 
      didReceiveRemoteNotification:(NSDictionary *) userInfo
          fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler {
    // Print full message.
    NSLog(@"APNs receive_message %@", userInfo);
    completionHandler(UIBackgroundFetchResultNewData);
}
// [START ios_10_message_handling]
// Receive displayed notifications for iOS 10 devices.
// Handle incoming notification messages while app is in the foreground.
- (void)userNotificationCenter:(UNUserNotificationCenter *)center
       willPresentNotification:(UNNotification *)notification
         withCompletionHandler:(void (^)(UNNotificationPresentationOptions))completionHandler API_AVAILABLE(ios(10.0)){
    NSDictionary *userInfo = notification.request.content.userInfo;
    // Print full message.
    [[GinSDK Firebase] showInAppMessage:userInfo];
    // Change this to your preferred presentation option
    completionHandler(UNNotificationPresentationOptionBadge);
}

// Handle notification messages after display notification is tapped by the user.
- (void)userNotificationCenter:(UNUserNotificationCenter *)center
didReceiveNotificationResponse:(UNNotificationResponse *)response
         withCompletionHandler:(void(^)(void))completionHandler {
  NSDictionary *userInfo = response.notification.request.content.userInfo;
    [[GinSDK Firebase] showInAppMessage:userInfo];
  completionHandler();
}
// [END ios_10_message_handling]
```

# API description and usage
## Initialize GinSDK
```objectivec
#import "GinSDK.h"
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [[GinSDK sharedInstance] initSdk:^(NSString *initStatus) {
        NSLog(@"initStatus = %@", initStatus);
        if ([initStatus isEqual:@"success"]) {
            NSLog(@"Gin init ok");
        } else {
            NSLog(@"Gin init failed");
        }
    }];
    //...
}
```

## Initialize GinSDK with Options (New in v2.0.2)
### Objective-C Implementation
```objectivec
#import "GinSDK.h"
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Create SDK options with modular control
    GinSDKOptions *options = [[GinSDKOptions alloc] init];
    options.enableAppsFlyer = YES;  // Enable AppsFlyer tracking
    options.enableFirebase = YES;   // Enable Firebase Analytics
    options.enableITS = YES;        // Enable ITS tracking
    
    // Initialize SDK with options
    [[GinSDK sharedInstance] initSdkWithOptions:options completion:^(NSString *initStatus) {
        NSLog(@"initStatus = %@", initStatus);
        if ([initStatus isEqual:@"success"]) {
            NSLog(@"Gin init with options ok");
        } else {
            NSLog(@"Gin init with options failed");
        }
    }];
    //...
}
```
**Note**: The traditional `initSdk:` method remains available for backward compatibility. The new `initSdkWithOptions:` provides enhanced control over which tracking modules to enable.

## Initialize SDK delegate
```objectivec
//MainViewController.h
@interface MainViewController:UIViewController<UIActionSheetDelegate, SKProductsRequestDelegate, LoginDelegate, LogoutDelegate, IAPDelegate> {
}
```
```objectivec
//MainViewController.m
#pragma Login Delegate
- (void)loginSuccess:(NSDictionary *)loginData {
    NSString *userID = loginData[@"user_id"];
    NSString *userName = loginData[@"user_name"];
    NSString *accessToken = loginData[@"auth_token"];
    NSString *checksum = loginData[@"auth_checksum"];
    NSString *timestamp = loginData[@"auth_timestamp"];
    // Your implementation here
}
- (void)loginFail:(NSString *)message {
}
#pragma Logout Delegate
- (void) logoutSuccess{
}
#pragma IAP Delegate
- (void) IAPInitFailed:(NSString *)message andErrorCode:(NSString *)errorCode {
}
- (void) IAPPurchaseFailed:(NSString *)message andErrorCode:(NSString *)errorCode {
}
- (void) IAPCompleted:(NSString *)message{
}
```
## Show Login/Logout Interface
```objectivec
[[GinSDK sharedInstance] showSignInView:self andResultDelegate:self];
//showSignInView: use as main view controller
//andResultDelegate: use as Login Delegate
[[GinSDK sharedInstance] IDSignOut:self];
//use as Logout Delegate
```

## Delete Account API
```objectivec
[[GinSDK sharedInstance] deleteAcount:self andCallback:^(NSDictionary *response) {
    NSLog(@"response = %@", response);
}];
```

## Using IAP
*** appleSecret default is empty (ex: @""), this will change when we send the request to you
  
```objectivec
IAPDataRequest *iapData = [[IAPDataRequest alloc] 
          initWithData:_userName 
          andOrderId:orderID 
          andOrderInfo:orderInfo 
          andServerID:server 
          andAmount:amount 
          andAppleProductID:productID 
          andAppleShareSecrect:appleSecret 
          andRoleID:character 
          andExtraInfo:extraInfo];
[[GinSDK sharedInstance] showIAP:(IAPDataRequest *)iapData andMainView:self andIAPDelegate:self];
//andMainView: use as main view controller
//andIAPDelegate: use as IAP Delegate
```

## Using WebView TopUp (New in 2.0.0)
*** New WebView-based TopUp system for enhanced user experience
  
```objectivec
// Create TopUp data object
GameItemWebTopupObject *topupInfo = [[GameItemWebTopupObject alloc] init];

// Set required parameters (these will be provided by your game server)
topupInfo.characterID = @"character_id";
topupInfo.characterName = @"character_name";
topupInfo.serverID = @"server_id";
topupInfo.productID = @"product_id";
topupInfo.productName = @"product_name";
topupInfo.amount = @"amount";
topupInfo.extraInfo = @"extra_info";

// Show TopUp with listener
[GinSDK showTopUp:topupInfo andListener:self];
```

### TopUp Delegate Methods
```objectivec
//MainViewController.h - Add IGameTopupListener protocol
@interface MainViewController:UIViewController<UIActionSheetDelegate, SKProductsRequestDelegate, LoginDelegate, LogoutDelegate, IAPDelegate, IGameTopupListener> {
}

//MainViewController.m - Implement TopUp delegate methods
#pragma TopUp Delegate
- (void)topUpSuccess:(NSString *)message {
    NSLog(@"TopUp Success: %@", message);
}
- (void)topUpFailed:(NSString *)errorMessage {
    NSLog(@"TopUp Failed: %@", errorMessage);
}
- (void)topUpCancelled {
    NSLog(@"TopUp Cancelled by user");
}
```

# API Tracking Events

```
USAGE TRACKING
--------------------
The SDK supports tracking in-app events. To use it, you need to implement the `GItsTrackingManager` module. For detailed information, refer to the code example below.
```objectivec
  [[GinSDK GTracking] completeRegistration:@"user_id"];
  [[GinSDK GTracking] trackingTurialCompleted];
```  
For detailed information on tracking events, please refer to the [Tracking Guide](./TRACKING_GUIDE.md).
By using the GinSDK for iOS you agree to these terms.

