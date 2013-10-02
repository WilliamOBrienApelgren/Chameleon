//
//  UIStoryboard.h
//  UIKit
//
//  Created by Derek van Vliet on 2013-10-02.
//
//

#import <Foundation/Foundation.h>

@interface UIStoryboard : NSObject

+ (UIStoryboard *)storyboardWithName:(NSString *)name bundle:(NSBundle *)storyboardBundleOrNil;

- (id)instantiateInitialViewController;
- (id)instantiateViewControllerWithIdentifier:(NSString *)identifier;

@end
