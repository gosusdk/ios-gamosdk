# iOS GinSDK Changelog

## [2.0.2] - 2025-11-24

### 🚀 New Features

#### AppsFlyer Integration
- **AppsFlyer Tracking Module**: Added comprehensive AppsFlyer SDK integration for advanced attribution and analytics
- **Native iOS Support**: Full iOS AppsFlyer SDK integration with Objective-C compatibility

#### Enhanced SDK Initialization
- **GinSDKOptions Configuration**: Introduced flexible SDK initialization options with modular enable/disable controls
  - **Module Control**: Enable/disable specific tracking modules using configuration options
    - `enableAppsFlyer` - Control AppsFlyer integration (YES/NO)
    - `enableITS` - Control ITS tracking module (YES/NO) 
    - `enableFirebase` - Control Firebase Analytics (YES/NO)

### 🔧 Enhanced Features

#### Initialization Flow
- **Improved SDK Setup**: Enhanced SDK initialization with configurable options
  - Better error handling and validation
  - Asynchronous initialization support
  - Backward compatibility with existing initialization methods
- **Configuration Validation**: Built-in validation for module configurations
- **Performance Optimization**: Only load enabled modules to reduce app overhead

### 📋 Configuration Updates

#### AppsFlyer Dependencies
- **Framework Integration**: 
```
  third-party/libs/AppsFlyer(6.17.7)/AppsFlyerLib.xcframework
```
#### SDK Options Configuration
- **Objective-C Implementation**:
  ```objectivec
  GinSDKOptions *options = [[GinSDKOptions alloc] init];
  options.enableAppsFlyer = YES;
  options.enableFirebase = YES;
  options.enableITS = YES;
  [GinSDK initializeWithOptions:options delegate:self];
  ```
  
#### Plist Configuration
- **AppsFlyer Settings**: New plist configuration keys
  ```xml
  <key>AppsflyerAppleID</key>
  <string>YOUR_APPLE_APP_ID</string>
  ```

### 🛠️ Technical Improvements

#### Analytics Integration
- **Unified Analytics**: Consolidated analytics interface supporting multiple providers
- **Event Tracking**: Enhanced event tracking with AppsFlyer attribution
- **Deep Linking**: AppsFlyer deep linking and deferred deep linking support
- **Attribution Data**: Real-time attribution data access through SDK callbacks

#### Framework Management
- **XCFramework**: AppsFlyer included as XCFramework for better compatibility
- **Privacy Compliance**: Enhanced privacy manifest updates for AppsFlyer integration
- **App Store Compliance**: Full App Store review guidelines compliance

### 🔄 Migration Notes

#### For Existing Implementations
- **Backward Compatibility**: Existing implementations continue to work without changes
- **Optional Migration**: Gradual adoption of new modular configuration system
- **Performance Benefits**: Automatic performance improvements with module-based loading

#### New Integration Steps
1. **Update SDK**: Upgrade to GinSDK 2.0.2
2. **Configure Options**: Implement GinSDKOptions for modular control
3. **AppsFlyer Setup**: Add AppsFlyer configuration keys to Info.plist
4. **Test Integration**: Verify module functionality and attribution tracking

**This guide shows you how to integrate your iOS app using the GinSDK for iOS. The GinSDK for iOS consists of the following component SDKs:**
  - The GinSDK Core
  - Third-party framework: 
      - GoogleSigin SDK, Firebase SDK, Facebook SDK, AppsFlyer SDK
      - Grpc Framework (GRPCClient, ProtoBuf, ProtoRPC, RxLibrary, ...)
      - Download at : (https://drive.google.com/file/d/18R6kx4lN4rJbM7-zyLabR0aAo2LUZ5Y6/view?usp=sharing)
  - Ios version support: 13+
---

## [2.0.1] - 2025-10-11

### 🔧 System Improvements

#### Third-Party Library Optimization
- **Airbridge Library Removal**: Completely removed Airbridge tracking library from the SDK
- **SDK Size Reduction**: Significantly reduced SDK bundle size by eliminating Airbridge dependencies
- **Performance Improvement**: Enhanced SDK initialization and runtime performance
- **Privacy Enhancement**: Improved user privacy by removing additional tracking components

### 🛠️ Technical Changes

#### Framework Dependencies
- **Removed Dependencies**: Airbridge tracking framework no longer required
- **Cleaner Integration**: Simplified framework integration process for developers
- **Reduced Complexity**: Streamlined SDK architecture with fewer external dependencies

### 📋 Migration Notes

#### For Existing Implementations
- **No Code Changes Required**: This update is fully backward compatible
- **Automatic Benefits**: Existing integrations will automatically benefit from reduced SDK size and improved performance
- **Framework Cleanup**: Developers can optionally remove Airbridge frameworks from their projects if not used elsewhere

#### Build Configuration
- **Framework References**: Remove Airbridge framework references from build settings if no longer needed
- **Bundle Size**: Expect reduced app bundle size after updating to version 2.0.1

---

## [2.0.0] - 2025-07-25

### 🚀 New Features

#### User Scope Validation System
- **Government Compliance**: Enhanced user authentication system to comply with national government regulations
- **User Verification**: Improved user identity verification process according to government decree requirements
- **Integration**: Enhanced OAuth flow with real-time scope verification

#### Enhanced Error Management System
- **Improved Error Messages**: Enhanced error messaging system for better clarity and understanding
- **User-Friendly**: More intuitive and understandable error messages for end users
- **Developer-Friendly**: Detailed error information and better debugging support for developers

#### Privacy & Compliance Enhancement
- **Privacy Manifest**: Comprehensive `PrivacyInfo.xcprivacy` file for App Store compliance
- **Data Collection Declaration**: Transparent documentation of data collection practices
- **API Usage Declaration**: Complete documentation of accessed iOS APIs

### 🔧 System Upgrades

#### Build System & Framework Management
- **SDK Version**: Updated to version 2.0.0
- **ITS SDK**: 1.1.1 → 1.1.2
- **Framework Organization**: Improved framework structure and dependency management
- **XCFramework Integration**: Enhanced XCFramework build process and validation

### 🐛 Bug Fixes

#### Dialog Management
- **Email TextField Cursor**: Fixed cursor visibility issue in email input dialogs
- **Email Verification Dialog**: Fixed email verification dialog sequencing and logic
- **Error Message Display**: Fixed incorrect error messages in dialogs

### ⚠️ Breaking Changes

#### Login Callback API Change
- **`loginSuccess` Method**: Signature changed from multiple parameters to single NSDictionary
  - **Old**: `- (void)loginSuccess:(NSString *)userID andUserName:(NSString *)userName andAccessToken:(NSString *)access_token`
  - **New**: `- (void)loginSuccess:(NSDictionary *)loginData`
  - **NSDictionary Format**:
    ```objectivec
    {
      "user_id": "value_of_userid",
      "user_name": "value_of_username", 
      "auth_checksum": "value_of_checksum",
      "auth_timestamp": "value",
      "auth_token": "value_of_accesstoken"
    }
    ```

#### API Changes

#### Framework Dependencies
- **ITS SDK Requirement**: Now requires ITS SDK 1.1.2 framework
- **Privacy Manifest**: Applications must include privacy manifest for App Store submissions

#### Scope Verification Flow
- **Email-First Verification**: Scope verification now requires email verification first

### 📋 Migration Notes

#### Required Updates
1. **Login Callback Migration**: Update `loginSuccess` implementation
   ```objectivec
   // Old implementation
   - (void)loginSuccess:(NSString *)userID andUserName:(NSString *)userName andAccessToken:(NSString *)access_token {
       // Your code here
   }
   
   // New implementation  
   - (void)loginSuccess:(NSDictionary *)loginData {
       NSString *userId = loginData[@"user_id"];
       NSString *userName = loginData[@"user_name"];
       NSString *accessToken = loginData[@"auth_token"];
       NSString *checksum = loginData[@"auth_checksum"];
       NSString *timestamp = loginData[@"auth_timestamp"];
       // Your code here
   }
   ```

2. **ITS Framework Integration**: Ensure ITS SDK 1.1.2 frameworks are included  
3. **Privacy Manifest**: Add privacy declarations to your app
4. **Build Configuration**: Update build scripts and framework dependencies

#### Optional Features
- **Enhanced Scope Validation**: Backward compatible with improved security
- **ITS Analytics**: Automatic integration - no code changes required for basic usage

---

**Note**: This release represents a major update to the iOS GinSDK with significant new features, enhanced security, and improved compliance. Please review the breaking changes and migration notes carefully before updating.
