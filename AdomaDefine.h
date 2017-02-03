//
//  版权所有,翻版必究
//  Created by adoma
//

// MainScreen Height&Width
#define Main_Screen_Height      [[UIScreen mainScreen] bounds].size.height
#define Main_Screen_Width       [[UIScreen mainScreen] bounds].size.width

// 系统控件默认高度
#define StatusBarHeight        (20.f)
#define TopBarHeight           (44.f)
#define BottomBarHeight        (49.f)
#define CellDefaultHeight      (44.f)
#define EnglishKeyboardHeight  (216.f)
#define ChineseKeyboardHeight  (252.f)

/// 沙盒路径
#define PATH_OF_APP_HOME    NSHomeDirectory()
#define PATH_OF_TEMP        NSTemporaryDirectory()
#define PATH_OF_DOCUMENT    [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0]

// 加载图片
#define PNGIMAGE(NAME)   [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(NAME) ofType:@"png"]]
#define JPGIMAGE(NAME)   [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(NAME) ofType:@"jpg"]]
#define IMAGE(NAME, EXT) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(NAME) ofType:(EXT)]]

// 颜色(RGB)
#define RGBCOLOR(r, g, b)       [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]
#define RGBACOLOR(r, g, b, a)   [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]
#define RGB16COLOR(rgbValue)    [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue &0xFF00) >>8))/255.0 blue:((float)(rgbValue &0xFF))/255.0 alpha:1.0]

//适配尺寸
#define ADHeightValue(value) ((value)/667.0f*[UIScreen mainScreen].bounds.size.height)
#define ADWidthValue(value)  ((value)/375.0f*[UIScreen mainScreen].bounds.size.width)

/// 当前语言
#define CURRENTLANGUAGE ([[NSLocale preferredLanguages] objectAtIndex:0])

// 本地化字符串
/** NSLocalizedString宏做的其实就是在当前bundle中查找资源文件名“Localizable.strings”(参数:键＋注释) */
#define LocalString(x, ...) NSLocalizedString(x, nil)

#define AppLocalString(x, ...) NSLocalizedStringFromTable(x, @"someName", nil)

#define IOS9 ([[[UIDevice currentDevice] systemVersion] floatValue] >=9.0 ? YES : NO)

#define IS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

#define IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)

#define IS_IPHONE_5 (IS_IPHONE && Main_Screen_Height == 568.0)

/****当前APP语言***/
#define APPLanguageIsEN  [[[NSUserDefaults standardUserDefaults] objectForKey:APPLanguageKey] hasPrefix:@"en"]

///设置多语言
#define ADSetLocalLanguage(Language) \
[[NSUserDefaults standardUserDefaults] setObject:Language forKey:APPLanguageKey];\
[UserDefaults synchronize];

///多语言加载文字
#define ADLocalizedString(key) \
[[NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"%@",[[NSUserDefaults standardUserDefaults] objectForKey:APPLanguageKey]] ofType:@"lproj"]] localizedStringForKey:(key) value:@"" table:nil]

///多语言加载图片
#define ADLocalizedImage(key) \
[UIImage imageWithContentsOfFile:[[NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"%@",[[NSUserDefaults standardUserDefaults] objectForKey:kLanguage]] ofType:@"lproj"]] pathForResource:key ofType:@"png"]]

/// 当前Bundle版本
#define kBundleVersion [[[NSBundle mainBundle] infoDictionary] valueForKey:@"CFBundleShortVersionString"]
/// 当前系统版本
#define kSystemVersion [UIDevice currentDevice].systemVersion.floatValue

/// block self
#define BlockWeakObject(o) __typeof(o) __weak
#define BlockWeakSelf BlockWeakObject(self)

/// NSUserDefaults 实例化
#define UserDefaults [NSUserDefaults standardUserDefaults]

/// View 圆角和加边框
#define ViewBorderRadius(View, Radius, Width, Color)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]]


/// View 圆角
#define ViewRadius(View, Radius)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES]

/// 设置上两角为圆角
#define ViewTopRadius(view,radius)\
UIBezierPath *maskPath = [UIBezierPath bezierPathWithRoundedRect:view.bounds byRoundingCorners:UIRectCornerTopLeft | UIRectCornerTopRight cornerRadii:CGSizeMake(radius, radius)];\
CAShapeLayer *maskLayer = [[CAShapeLayer alloc] init];\
maskLayer.frame = view.bounds;\
maskLayer.path = maskPath.CGPath;\
view.layer.mask = maskLayer


/// 设置下两角为圆角
#define ViewBottomRadius(view,radius)\
UIBezierPath *maskPath = [UIBezierPath bezierPathWithRoundedRect:view.bounds byRoundingCorners:UIRectCornerBottomLeft | UIRectCornerBottomRight cornerRadii:CGSizeMake(radius, radius)];\
CAShapeLayer *maskLayer = [[CAShapeLayer alloc] init];\
maskLayer.frame = view.bounds;\
maskLayer.path = maskPath.CGPath;\
view.layer.mask = maskLayer

///读取XIB
#define LoadNibFrom(self) [[[NSBundle mainBundle] loadNibNamed:NSStringFromClass(self) owner:nil options:nil] lastObject]

/// LOG宏
#ifdef DEBUG
#define ADLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
#define ADLog(...)
#endif

//是否开启定位
#define isOpenLocation ([CLLocationManager locationServicesEnabled] && [CLLocationManager authorizationStatus] != kCLAuthorizationStatusDenied) 

#import <UIKit/UIKit.h>
@interface UIView (ext)

@property (nonatomic,assign)  CGFloat x;
@property (nonatomic,assign)  CGFloat y;

@property (nonatomic,assign)  CGFloat width;
@property (nonatomic,assign)  CGFloat height;

@property (nonatomic,assign)  CGPoint origin;
@property (nonatomic,assign)  CGSize  size;

@property (nonatomic,assign)  CGFloat centerX;
@property (nonatomic,assign)  CGFloat centerY;

@property (nonatomic,assign,readonly)  CGFloat MinX;
@property (nonatomic,assign,readonly)  CGFloat MinY;

@property (nonatomic,assign,readonly)  CGFloat MidX;
@property (nonatomic,assign,readonly)  CGFloat MidY;

@property (nonatomic,assign,readonly)  CGFloat MaxX;
@property (nonatomic,assign,readonly)  CGFloat MaxY;

@end

@interface UIColor (ext)

+ (UIColor *)randomColor;

@end
