L     ^       .rsrc             <   T         @ 0�    ���Y       H  �  �    ���Y          0  �    ���Y       	  d    W I N E _ R E G I S T R Y t   �          HKCR
{
    NoRemove Interface
    {
    }
    NoRemove CLSID
    {
        '{79EAC9D0-BAF9-11CE-8C82-00AA004BA90B}' = s 'StdHlink'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{79EAC9D1-BAF9-11CE-8C82-00AA004BA90B}' = s 'StdHlinkBrowseContext'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
    }
}
  d        .rsrc              