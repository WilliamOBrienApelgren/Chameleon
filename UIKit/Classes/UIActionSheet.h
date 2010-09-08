//  Created by Sean Heber on 6/25/10.
#import "UIView.h"

@class UIActionSheet, UIPopoverController;

@protocol UIActionSheetDelegate <NSObject>
@optional
- (void)actionSheet:(UIActionSheet *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex;
- (void)willPresentActionSheet:(UIActionSheet *)actionSheet;
- (void)didPresentActionSheet:(UIActionSheet *)actionSheet;
- (void)actionSheet:(UIActionSheet *)actionSheet willDismissWithButtonIndex:(NSInteger)buttonIndex;
- (void)actionSheet:(UIActionSheet *)actionSheet didDismissWithButtonIndex:(NSInteger)buttonIndex;
- (void)actionSheetCancel:(UIActionSheet *)actionSheet;
@end

@interface UIActionSheet : UIView {
@private
	id<UIActionSheetDelegate> _delegate;
	NSInteger _destructiveButtonIndex;
	NSInteger _cancelButtonIndex;
	NSString *_title;
	NSMutableArray *_buttons;
	UIPopoverController *_popoverController;
	
	struct {
		unsigned int clickedButtonAtIndex : 1;
		unsigned int willPresentActionSheet : 1;
		unsigned int didPresentActionSheet : 1;
		unsigned int willDismissWithButtonIndex : 1;
		unsigned int didDismissWithButtonIndex : 1;
		unsigned int actionSheetCancel : 1;
	} _delegateHas;
}

- (id)initWithTitle:(NSString *)title delegate:(id<UIActionSheetDelegate>)delegate cancelButtonTitle:(NSString *)cancelButtonTitle destructiveButtonTitle:(NSString *)destructiveButtonTitle otherButtonTitles:(NSString *)otherButtonTitles, ...;
- (NSInteger)addButtonWithTitle:(NSString *)title;

- (void)showInView:(UIView *)view;
- (void)showFromRect:(CGRect)rect inView:(UIView *)view animated:(BOOL)animated;
- (void)dismissWithClickedButtonIndex:(NSInteger)buttonIndex animated:(BOOL)animated;

@property (nonatomic, copy) NSString *title;
@property (nonatomic, assign) id<UIActionSheetDelegate> delegate;
@property (nonatomic, readonly, getter=isVisible) BOOL visible;
@property (nonatomic) NSInteger destructiveButtonIndex;
@property (nonatomic) NSInteger cancelButtonIndex;

@end
