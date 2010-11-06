/*
 *  hdGraphicsLibrary
 */

#import "iGLESSurface.h"
#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>



@class iGLView;

@interface iGLView : UIView <iGLESSurfaceDelegate>
{
@private
	BOOL _autoresize;
	CGSize _size;
	iGLESSurface<iGLESAbstractSurface> *_surface;
}

@property BOOL autoresizesSurface;
@property(readonly, nonatomic) CGSize surfaceSize;

- (id) initWithFrame:(CGRect)frame;
- (void) swapBuffers;
- (void) setCurrentContext;

@end
