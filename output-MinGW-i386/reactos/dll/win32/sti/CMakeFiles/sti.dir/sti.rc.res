L     R       .rsrc             <   H         @ 0�    ���Y       H  �  �    ���Y          0  �    ���Y       	  d    W I N E _ R E G I S T R Y t   �          HKCR
{
    NoRemove Interface
    {
        '{5EB2502A-8CF1-11D1-BF92-0060081ED811}' = s 'IWiaDevMgr'
        {
            NumMethods = s 12
            ProxyStubClsid32 = s '{4DB1AD10-3391-11D2-9A33-00C04FA36145}'
        }
        '{5E38B83C-8CF1-11D1-BF92-0060081ED811}' = s 'IEnumWIA_DEV_INFO'
        {
            NumMethods = s 3
            ProxyStubClsid32 = s '{4DB1AD10-3391-11D2-9A33-00C04FA36145}'
        }
        '{4DB1AD10-3391-11D2-9A33-00C04FA36145}' = s 'IWiaItem'
        {
            NumMethods = s 3
            ProxyStubClsid32 = s '{4DB1AD10-3391-11D2-9A33-00C04FA36145}'
        }
        '{AE6287B0-0084-11D2-973B-00A0C9068F2E}' = s 'IWiaEventCallback'
        {
            NumMethods = s 4
            ProxyStubClsid32 = s '{4DB1AD10-3391-11D2-9A33-00C04FA36145}'
        }
    }
    NoRemove CLSID
    {
        '{4DB1AD10-3391-11D2-9A33-00C04FA36145}' = s 'PSFactoryBuffer'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{B323F8E0-2E68-11D0-90EA-00AA0060F86C}' = s 'StillImage'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
   d        .rsrc              