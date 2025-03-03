//
//  ABSetting.h
//  AirBridge
//
//  Created by WOF on 09/09/2019.
//  Copyright © 2019 ab180. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AirBridge/ABInAppPurchase.h>
#import <AirBridge/ABInAppPurchaseEnvironment.h>

NS_ASSUME_NONNULL_BEGIN

typedef uint64_t ABMillisecond;
typedef void (^ABAttributionCallback)(NSDictionary<NSString*, NSString*>* __nonnull attribution);
typedef ABInAppPurchase * _Nonnull (^ABInAppPurchaseCallback)(ABInAppPurchase *inAppPurchase);

@interface ABSetting : NSObject

@property ABMillisecond trackingAuthorizeTimeout;
@property BOOL isRestartTrackingAuthorizeTimeout;
@property ABAttributionCallback attributionCallback;
@property BOOL isResetEventBufferEnabled;

@property (nonatomic, strong) ABInAppPurchaseCallback inAppPurchaseCallback;

- (void)setTrackInSessionLifeCycleEventEnabled:(BOOL)enabled;
- (void)setEventMaximumBufferCount:(uint64_t)eventMaximumBufferCount;
- (void)setEventMaximumBufferSize:(uint64_t)eventMaximumBufferSize;
- (void)setEventTransmitInterval:(uint64_t)milliseconds;

- (void)setOnInAppPurchaseReceived:(ABInAppPurchaseCallback)callback;
- (void)setInAppPurchaseEnvironment:(ABInAppPurchaseEnvironment)environment;

@end

NS_ASSUME_NONNULL_END
