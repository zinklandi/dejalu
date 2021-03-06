// DejaLu
// Copyright (c) 2015 Hoa V. DINH. All rights reserved.

#import <AppKit/AppKit.h>

@interface DJLGenericCompletionWindowController : NSWindowController {
	NSScrollView * _scrollView;
	NSTableView * _tableView;
    __unsafe_unretained NSTextField * _field;
    BOOL _disableValidation;
    BOOL _isValidatingToken;
    BOOL _menuLookEnabled;
    NSUInteger _itemsCount;
    NSControlSize _controlSize;
    CGFloat _deltaYPosition;
}

@property (nonatomic, assign) NSTextField * field;
@property (nonatomic, assign) BOOL menuLookEnabled;
@property (nonatomic, assign) NSControlSize controlSize;
@property (nonatomic, assign) CGFloat deltaYPosition;

- (void) complete;

- (void) cancelCompletion;
- (void) previousCompletion;
- (void) nextCompletion;
- (void) pageDown;
- (void) pageUp;
- (void) acceptCompletion;
- (BOOL) canAcceptCompletion;
- (NSString *) originalStringToComplete;

- (BOOL) control:(NSControl *)control textView:(NSTextView *)textView doCommandBySelector:(SEL)command;

// tools
- (void) replaceWithCompletion:(NSString *)completion;
- (void) replaceWithAttributedCompletion:(NSAttributedString *)completion;
- (NSInteger) selectedCompletionIndex;

// to be overriden
- (NSUInteger) prepareTableViewContentsWithStringValue:(NSString *)value;
- (void) didBuildUI;

@end
