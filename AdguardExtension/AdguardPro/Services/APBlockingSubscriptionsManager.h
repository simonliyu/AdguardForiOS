/**
    This file is part of Adguard for iOS (https://github.com/AdguardTeam/AdguardForiOS).
    Copyright © 2015-2017 Performix LLC. All rights reserved.
 
    Adguard for iOS is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
 
    Adguard for iOS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
 
    You should have received a copy of the GNU General Public License
    along with Adguard for iOS.  If not, see <http://www.gnu.org/licenses/>.
 */

#import <Foundation/Foundation.h>

#import "APBlockingSubscription.h"

/////////////////////////////////////////////////////////////////
/**
 class APBlockingSubscriptionsManager
 manages blocking subscriptions
 */

@interface APBlockingSubscriptionsManager : NSObject

/**
 list of added subscriptions
 */
@property (class, nonatomic) NSArray<APBlockingSubscription*> *subscriptions;

/**
 list of predefined subscriptions
 */
@property (class, nonatomic, readonly) NSArray<APBlockingSubscription*> *predefinedSubscriptions;

/**
 load all hosts dictionary from file
 */
+ (NSDictionary*) loadHosts;

/**
load all rules array from file
 */
+ (NSArray<NSString*> *) loadRules;

/**
 check the domain is in hosts
 */
+ (APBlockingSubscription*) checkDomain:(NSString*) domain;

/**
 check need update subscriptions
 */
+ (BOOL) needUpdateSubscriptions;

/**
 update all subscriptions
 */
+ (void) updateSubscriptionsWithSuccessBlock:(void (^)())successBlock errorBlock:(void (^)(NSError *))errorBlock completionBlock:(void (^)())completionBlock;

@end
