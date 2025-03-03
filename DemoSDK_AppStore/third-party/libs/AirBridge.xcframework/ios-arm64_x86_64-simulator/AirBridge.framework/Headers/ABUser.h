//
//  ABUser.h
//  AirBridge
//
//  Created by donutt on 2017. 8. 9..
//  Copyright © 2017년 TehranSlippers. All rights reserved.
//

#import <AirBridge/ABData.h>
#import <Foundation/Foundation.h>

@interface ABUser : NSObject <ABData, NSSecureCoding, NSCopying>

@property NSString* ID;
@property NSString* email;
@property NSString* phone;
@property (getter=alias, setter=setAlias:) NSDictionary<NSString*, NSString*>* alias;
@property (getter=attributes, setter=setAttributes:) NSDictionary<NSString*, NSObject*>* attributes;

- (void) hashDatas;

// DEPRECATED
@property (getter=ID, setter=setID:) NSString* userID __deprecated_msg("use ID instead");
@property (getter=email, setter=setEmail:) NSString* userEmail __deprecated_msg("use email instead");
@property (getter=phone, setter=setPhone:) NSString* userPhone __deprecated_msg("use phone instead");

@end
