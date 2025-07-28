# iOS GinSDK Changelog

## [2.0.0] - 2025-07-25

### 🚀 New Features

#### WebView TopUp System
- **New API**: `+ (void) showTopUp:(GameItemWebTopupObject *) topUpInfo andListener:(id<IGameTopupListener>) listener`
- **Classes Added**: 
  - `GameItemWebTopupObject`: TopUp transaction data object
  - `IGameTopupListener`: TopUp event callback protocol
- **Features**: Built-in validation, error handling, and comprehensive callback system

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
- **TopUp Method Signature**: Changed from instance method to class method
  - **Old**: Instance method implementation
  - **New**: `+ (void) showTopUp:(GameItemWebTopupObject *) topUpInfo andListener:(id<IGameTopupListener>) listener`

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

2. **TopUp Integration**: Update to new class method signature
3. **ITS Framework Integration**: Ensure ITS SDK 1.1.2 frameworks are included  
4. **Privacy Manifest**: Add privacy declarations to your app
5. **Build Configuration**: Update build scripts and framework dependencies

#### Optional Features
- **WebView TopUp System**: Backward compatible - can be adopted gradually
- **Enhanced Scope Validation**: Backward compatible with improved security
- **ITS Analytics**: Automatic integration - no code changes required for basic usage

---

**Note**: This release represents a major update to the iOS GinSDK with significant new features, enhanced security, and improved compliance. Please review the breaking changes and migration notes carefully before updating.
