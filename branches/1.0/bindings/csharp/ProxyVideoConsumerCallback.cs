/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.39
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

namespace org.doubango.tinyWRAP {

using System;
using System.Runtime.InteropServices;

public class ProxyVideoConsumerCallback : IDisposable {
  private HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal ProxyVideoConsumerCallback(IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new HandleRef(this, cPtr);
  }

  internal static HandleRef getCPtr(ProxyVideoConsumerCallback obj) {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }

  ~ProxyVideoConsumerCallback() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if(swigCPtr.Handle != IntPtr.Zero && swigCMemOwn) {
        swigCMemOwn = false;
        tinyWRAPPINVOKE.delete_ProxyVideoConsumerCallback(swigCPtr);
      }
      swigCPtr = new HandleRef(null, IntPtr.Zero);
      GC.SuppressFinalize(this);
    }
  }

  public ProxyVideoConsumerCallback() : this(tinyWRAPPINVOKE.new_ProxyVideoConsumerCallback(), true) {
    SwigDirectorConnect();
  }

  public virtual int prepare(int width, int height, int fps) {
    int ret = ((this.GetType() == typeof(ProxyVideoConsumerCallback)) ? tinyWRAPPINVOKE.ProxyVideoConsumerCallback_prepare(swigCPtr, width, height, fps) : tinyWRAPPINVOKE.ProxyVideoConsumerCallback_prepareSwigExplicitProxyVideoConsumerCallback(swigCPtr, width, height, fps));
    return ret;
  }

  public virtual int consume(ProxyVideoFrame frame) {
    int ret = ((this.GetType() == typeof(ProxyVideoConsumerCallback)) ? tinyWRAPPINVOKE.ProxyVideoConsumerCallback_consume(swigCPtr, ProxyVideoFrame.getCPtr(frame)) : tinyWRAPPINVOKE.ProxyVideoConsumerCallback_consumeSwigExplicitProxyVideoConsumerCallback(swigCPtr, ProxyVideoFrame.getCPtr(frame)));
    return ret;
  }

  public virtual int start() {
    int ret = ((this.GetType() == typeof(ProxyVideoConsumerCallback)) ? tinyWRAPPINVOKE.ProxyVideoConsumerCallback_start(swigCPtr) : tinyWRAPPINVOKE.ProxyVideoConsumerCallback_startSwigExplicitProxyVideoConsumerCallback(swigCPtr));
    return ret;
  }

  public virtual int pause() {
    int ret = ((this.GetType() == typeof(ProxyVideoConsumerCallback)) ? tinyWRAPPINVOKE.ProxyVideoConsumerCallback_pause(swigCPtr) : tinyWRAPPINVOKE.ProxyVideoConsumerCallback_pauseSwigExplicitProxyVideoConsumerCallback(swigCPtr));
    return ret;
  }

  public virtual int stop() {
    int ret = ((this.GetType() == typeof(ProxyVideoConsumerCallback)) ? tinyWRAPPINVOKE.ProxyVideoConsumerCallback_stop(swigCPtr) : tinyWRAPPINVOKE.ProxyVideoConsumerCallback_stopSwigExplicitProxyVideoConsumerCallback(swigCPtr));
    return ret;
  }

  private void SwigDirectorConnect() {
    if (SwigDerivedClassHasMethod("prepare", swigMethodTypes0))
      swigDelegate0 = new SwigDelegateProxyVideoConsumerCallback_0(SwigDirectorprepare);
    if (SwigDerivedClassHasMethod("consume", swigMethodTypes1))
      swigDelegate1 = new SwigDelegateProxyVideoConsumerCallback_1(SwigDirectorconsume);
    if (SwigDerivedClassHasMethod("start", swigMethodTypes2))
      swigDelegate2 = new SwigDelegateProxyVideoConsumerCallback_2(SwigDirectorstart);
    if (SwigDerivedClassHasMethod("pause", swigMethodTypes3))
      swigDelegate3 = new SwigDelegateProxyVideoConsumerCallback_3(SwigDirectorpause);
    if (SwigDerivedClassHasMethod("stop", swigMethodTypes4))
      swigDelegate4 = new SwigDelegateProxyVideoConsumerCallback_4(SwigDirectorstop);
    tinyWRAPPINVOKE.ProxyVideoConsumerCallback_director_connect(swigCPtr, swigDelegate0, swigDelegate1, swigDelegate2, swigDelegate3, swigDelegate4);
  }

  private bool SwigDerivedClassHasMethod(string methodName, Type[] methodTypes) {
    System.Reflection.MethodInfo methodInfo = this.GetType().GetMethod(methodName, System.Reflection.BindingFlags.Public | System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance, null, methodTypes, null);
    bool hasDerivedMethod = methodInfo.DeclaringType.IsSubclassOf(typeof(ProxyVideoConsumerCallback));
    return hasDerivedMethod;
  }

  private int SwigDirectorprepare(int width, int height, int fps) {
    return prepare(width, height, fps);
  }

  private int SwigDirectorconsume(IntPtr frame) {
    return consume((frame == IntPtr.Zero) ? null : new ProxyVideoFrame(frame, false));
  }

  private int SwigDirectorstart() {
    return start();
  }

  private int SwigDirectorpause() {
    return pause();
  }

  private int SwigDirectorstop() {
    return stop();
  }

  public delegate int SwigDelegateProxyVideoConsumerCallback_0(int width, int height, int fps);
  public delegate int SwigDelegateProxyVideoConsumerCallback_1(IntPtr frame);
  public delegate int SwigDelegateProxyVideoConsumerCallback_2();
  public delegate int SwigDelegateProxyVideoConsumerCallback_3();
  public delegate int SwigDelegateProxyVideoConsumerCallback_4();

  private SwigDelegateProxyVideoConsumerCallback_0 swigDelegate0;
  private SwigDelegateProxyVideoConsumerCallback_1 swigDelegate1;
  private SwigDelegateProxyVideoConsumerCallback_2 swigDelegate2;
  private SwigDelegateProxyVideoConsumerCallback_3 swigDelegate3;
  private SwigDelegateProxyVideoConsumerCallback_4 swigDelegate4;

  private static Type[] swigMethodTypes0 = new Type[] { typeof(int), typeof(int), typeof(int) };
  private static Type[] swigMethodTypes1 = new Type[] { typeof(ProxyVideoFrame) };
  private static Type[] swigMethodTypes2 = new Type[] {  };
  private static Type[] swigMethodTypes3 = new Type[] {  };
  private static Type[] swigMethodTypes4 = new Type[] {  };
}

}
