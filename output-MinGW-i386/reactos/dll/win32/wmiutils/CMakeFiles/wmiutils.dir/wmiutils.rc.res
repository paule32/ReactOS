L     ^       .rsrc             <   T         @ 0�    ���Y       H  �  �    ���Y          0  �    ���Y       	  d    W I N E _ R E G I S T R Y t   �          HKCR
{
    NoRemove Interface
    {
    }
    NoRemove CLSID
    {
        '{CF4CC405-E2C5-4DDD-B3CE-5E7582D8C9FA}' = s 'WbemDefPath'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{EB87E1BD-3233-11D2-AEC9-00C04FB68820}' = s 'WbemStatusCode'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
} d        .rsrc              