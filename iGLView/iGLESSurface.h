/*
 *  hdGraphicsLibrary
 */

#import <QuartzCore/QuartzCore.h>
#import <OpenGLES/EAGL.h>
#import <OpenGLES/EAGLDrawable.h>

@protocol iGLESSurfaceDelegate <NSObject>
@required
- (CAEAGLLayer *) getLayer;
- (CGRect) getBounds;
@end


@protocol iGLESAbstractSurface <NSObject>
@required
- (BOOL) createSurface;
- (void) destroySurface;
- (void) bindFrameBuffer;
- (void) bindRenderBufferAndPresent;
- (void) swapBuffers;
@end


@interface iGLESSurface : NSObject
{
@protected
	EAGLContext *_context;
	BOOL _hasBeenCurrent;
	id<iGLESSurfaceDelegate> _delegate;
}

- (void) setCurrentContext;
- (BOOL) isCurrentContext;
- (void) clearCurrentContext;

@property(readonly) EAGLContext *context;
@property(assign) id<iGLESSurfaceDelegate> delegate;

@end