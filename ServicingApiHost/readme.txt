======================
   ServicingApiHost
======================

Make multiple offline "CbsCore.dll"s to be loaded possible.

It's a simple single-use out-of-process COM server, register itself
by the GUID parameter as the coclass. We use dynamic GUID to acquire
different ApiHost instance.

For the functionality, it's just a IClassFactory wrapper.
