;  
 ;   i o l o g m s g . m c   M E S S A G E   r e s o u r c e s   f o r   i o l o g m s g . d l l  
 ;  
  
 M e s s a g e I d T y p e d e f = N T S T A T U S  
  
 S e v e r i t y N a m e s = ( S u c c e s s = 0 x 0 : S T A T U S _ S E V E R I T Y _ S U C C E S S  
                               I n f o r m a t i o n a l = 0 x 1 : S T A T U S _ S E V E R I T Y _ I N F O R M A T I O N A L  
                               W a r n i n g = 0 x 2 : S T A T U S _ S E V E R I T Y _ W A R N I N G  
                               E r r o r = 0 x 3 : S T A T U S _ S E V E R I T Y _ E R R O R  
                             )  
  
 F a c i l i t y N a m e s = ( R p c R u n t i m e = 0 x 2 : F A C I L I T Y _ R P C _ R U N T I M E  
                               R p c S t u b s = 0 x 3 : F A C I L I T Y _ R P C _ S T U B S  
                               I O = 0 x 4 : F A C I L I T Y _ I O _ E R R O R _ C O D E  
                               M C A = 0 x 5 : F A C I L I T Y _ M C A _ E R R O R _ C O D E  
                             )  
  
 L a n g u a g e N a m e s = ( E n g l i s h = 0 x 4 0 9 : M S G 0 0 4 0 9 )  
  
  
 ;  
 ;   m e s s a g e   d e f i n i t i o n s  
 ;  
  
 ;   F a c i l i t y = I O  
  
 ;   I O   E r r o r   m e s s a g e s  
  
 M e s s a g e I d = 1  
 S e v e r i t y = S u c c e s s  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ E R R _ R E T R Y _ S U C C E E D E D  
 L a n g u a g e = E n g l i s h  
 A   r e t r y   s u c c e e d e d .  
 .  
  
 M e s s a g e I d = 2  
 S e v e r i t y = E r r o r  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ E R R _ I N S U F F I C I E N T _ R E S O U R C E S  
 L a n g u a g e = E n g l i s h  
 I n s u f f i c i e n t   r e s o u r c e s .  
 .  
  
 M e s s a g e I d = 3  
 S e v e r i t y = E r r o r  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ E R R _ C O N F I G U R A T I O N _ E R R O R  
 L a n g u a g e = E n g l i s h  
 D r i v e r   o r   d e v i c e   i s   i n c o r r e c t l y   c o n f i g u r e d   f o r   % 1 .  
 .  
  
 M e s s a g e I d = 4  
 S e v e r i t y = E r r o r  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ E R R _ D R I V E R _ E R R O R  
 L a n g u a g e = E n g l i s h  
 D r i v e r   d e t e c t e d   a n   i n t e r n a l   e r r o r   i n   i t s   d a t a   s t r u c t u r e s   f o r   % 1 .  
 .  
  
 M e s s a g e I d = 5  
 S e v e r i t y = E r r o r  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ E R R _ P A R I T Y  
 L a n g u a g e = E n g l i s h  
 A   p a r i t y   e r r o r   w a s   d e t e c t e d   o n   % 1 .  
 .  
  
 M e s s a g e I d = 6  
 S e v e r i t y = E r r o r  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ E R R _ S E E K _ E R R O R  
 L a n g u a g e = E n g l i s h  
 T h e   d e v i c e ,   % 1 ,   h a d   a   s e e k   e r r o r .  
 .  
  
 M e s s a g e I d = 7  
 S e v e r i t y = E r r o r  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ E R R _ B A D _ B L O C K  
 L a n g u a g e = E n g l i s h  
 T h e   d e v i c e ,   % 1 ,   h a s   a   b a d   b l o c k .  
 .  
  
 M e s s a g e I d = 8  
 S e v e r i t y = E r r o r  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ E R R _ O V E R R U N _ E R R O R  
 L a n g u a g e = E n g l i s h  
 A n   o v e r r u n   o c c u r r e d   o n   % 1 .  
 .  
  
 M e s s a g e I d = 9  
 S e v e r i t y = E r r o r  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ E R R _ T I M E O U T  
 L a n g u a g e = E n g l i s h  
 T h e   d e v i c e ,   % 1 ,   d i d   n o t   r e s p o n d   w i t h i n   t h e   t i m e o u t   p e r i o d .  
 .  
  
 M e s s a g e I d = 1 0  
 S e v e r i t y = E r r o r  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ E R R _ S E Q U E N C E  
 L a n g u a g e = E n g l i s h  
 T h e   d r i v e r   d e t e c t e d   a n   u n e x p e c t e d   s e q u e n c e   b y   t h e   d e v i c e ,   % 1 .  
 .  
  
 M e s s a g e I d = 1 1  
 S e v e r i t y = E r r o r  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ E R R _ C O N T R O L L E R _ E R R O R  
 L a n g u a g e = E n g l i s h  
 T h e   d r i v e r   d e t e c t e d   a   c o n t r o l l e r   e r r o r   o n   % 1 .  
 .  
  
 M e s s a g e I d = 1 2  
 S e v e r i t y = E r r o r  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ E R R _ I N T E R N A L _ E R R O R  
 L a n g u a g e = E n g l i s h  
 T h e   d r i v e r   d e t e c t e d   a n   i n t e r n a l   d r i v e r   e r r o r   o n   % 1 .  
 .  
  
 M e s s a g e I d = 1 3  
 S e v e r i t y = E r r o r  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ E R R _ I N C O R R E C T _ I R Q L  
 L a n g u a g e = E n g l i s h  
 T h e   d r i v e r   w a s   c o n f i g u r e d   w i t h   a n   i n c o r r e c t   i n t e r r u p t   f o r   % 1 .  
 .  
  
 M e s s a g e I d = 1 4  
 S e v e r i t y = E r r o r  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ E R R _ I N V A L I D _ I O B A S E  
 L a n g u a g e = E n g l i s h  
 T h e   d r i v e r   w a s   c o n f i g u r e d   w i t h   a n   i n v a l i d   I / O   b a s e   a d d r e s s   f o r   % 1 .  
 .  
  
 M e s s a g e I d = 1 5  
 S e v e r i t y = E r r o r  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ E R R _ N O T _ R E A D Y  
 L a n g u a g e = E n g l i s h  
 I n s u f f i c i e n t   r e s o u r c e s .  
 .  
  
 M e s s a g e I d = 1 6  
 S e v e r i t y = E r r o r  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ E R R _ I N V A L I D _ R E Q U E S T  
 L a n g u a g e = E n g l i s h  
 T h e   r e q u e s t   i s   i n c o r r e c t l y   f o r m a t t e d   f o r   % 1 .  
 .  
  
 M e s s a g e I d = 1 7  
 S e v e r i t y = E r r o r  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ E R R _ V E R S I O N  
 L a n g u a g e = E n g l i s h  
 T h e   w r o n g   v e r s i o n   o f   t h e   d r i v e r   h a s   b e e n   l o a d e d .  
 .  
  
 M e s s a g e I d = 1 8  
 S e v e r i t y = E r r o r  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ E R R _ L A Y E R E D _ F A I L U R E  
 L a n g u a g e = E n g l i s h  
 T h e   d r i v e r   b e n e a t h   t h i s   o n e   h a s   f a i l e d   i n   s o m e   w a y   f o r   % 1 .  
 .  
  
 M e s s a g e I d = 1 9  
 S e v e r i t y = E r r o r  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ E R R _ R E S E T  
 L a n g u a g e = E n g l i s h  
 T h e   d e v i c e ,   % 1 ,   h a s   b e e n   r e s e t .  
 .  
  
 M e s s a g e I d = 2 0  
 S e v e r i t y = E r r o r  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ E R R _ P R O T O C O L  
 L a n g u a g e = E n g l i s h  
 A   t r a n s p o r t   d r i v e r   r e c e i v e d   a   f r a m e   w h i c h   v i o l a t e d   t h e   p r o t o c o l .  
 .  
  
 M e s s a g e I d = 2 1  
 S e v e r i t y = E r r o r  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ E R R _ M E M O R Y _ C O N F L I C T _ D E T E C T E D  
 L a n g u a g e = E n g l i s h  
 A   c o n f l i c t   h a s   b e e n   d e t e c t e d   b e t w e e n   t w o   d r i v e r s   w h i c h   c l a i m e d   t w o   o v e r l a p p i n g  
 m e m o r y   r e g i o n s .  
 D r i v e r   % 2 ,   w i t h   d e v i c e   < % 3 > ,   c l a i m e d   a   m e m o r y   r a n g e   w i t h   s t a r t i n g   a d d r e s s  
 i n   d a t a   a d d r e s s   0 x 2 8   a n d   0 x 2 c ,   a n d   l e n g t h   i n   d a t a   a d d r e s s   0 x 3 0 .  
 .  
  
 M e s s a g e I d = 2 2  
 S e v e r i t y = E r r o r  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ E R R _ P O R T _ C O N F L I C T _ D E T E C T E D  
 L a n g u a g e = E n g l i s h  
 A   c o n f l i c t   h a s   b e e n   d e t e c t e d   b e t w e e n   t w o   d r i v e r s   w h i c h   c l a i m e d   t w o   o v e r l a p p i n g  
 I o   p o r t   r e g i o n s .  
 D r i v e r   % 2 ,   w i t h   d e v i c e   < % 3 > ,   c l a i m e d   a n   I O   p o r t   r a n g e   w i t h   s t a r t i n g   a d d r e s s  
 i n   d a t a   a d d r e s s   0 x 2 8   a n d   0 x 2 c ,   a n d   l e n g t h   i n   d a t a   a d d r e s s   0 x 3 0 .  
 .  
  
 M e s s a g e I d = 2 3  
 S e v e r i t y = E r r o r  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ E R R _ D M A _ C O N F L I C T _ D E T E C T E D  
 L a n g u a g e = E n g l i s h  
 A   c o n f l i c t   h a s   b e e n   d e t e c t e d   b e t w e e n   t w o   d r i v e r s   w h i c h   c l a i m e d   e q u i v a l e n t   D M A  
 c h a n n e l s .  
 D r i v e r   % 2 ,   w i t h   d e v i c e   < % 3 > ,   c l a i m e d   t h e   D M A   C h a n n e l   i n   d a t a   a d d r e s s   0 x 2 8 ,   w i t h  
 o p t i n a l   p o r t   i n   d a t a   a d d r e s s   0 x 2 c .  
 .  
  
 M e s s a g e I d = 2 4  
 S e v e r i t y = E r r o r  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ E R R _ I R Q _ C O N F L I C T _ D E T E C T E D  
 L a n g u a g e = E n g l i s h  
 A   c o n f l i c t   h a s   b e e n   d e t e c t e d   b e t w e e n   t w o   d r i v e r s   w h i c h   c l a i m e d   e q u i v a l e n t   I R Q s .  
 D r i v e r   % 2 ,   w i t h   d e v i c e   < % 3 > ,   c l a i m e d   a n   i n t e r r u p t   w i t h   L e v e l   i n   d a t a   a d d r e s s  
 0 x 2 8 ,   v e c t o r   i n   d a t a   a d d r e s s   0 x 2 c   a n d   A f f i n i t y   i n   d a t a   a d d r e s s   0 x 3 0 .  
 .  
  
 M e s s a g e I d = 2 5  
 S e v e r i t y = E r r o r  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ E R R _ B A D _ F I R M W A R E  
 L a n g u a g e = E n g l i s h  
 I n s u f f i c i e n t   r e s o u r c e s .  
 T h e   d r i v e r   h a s   d e t e c t e d   a   d e v i c e   w i t h   o l d   o r   o u t - o f - d a t e   f i r m w a r e .   T h e  
 d e v i c e   w i l l   n o t   b e   u s e d .  
 .  
  
 M e s s a g e I d = 2 6  
 S e v e r i t y = W a r n i n g  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ W R N _ B A D _ F I R M W A R E  
 L a n g u a g e = E n g l i s h  
 T h e   d r i v e r   h a s   d e t e c t e d   t h a t   d e v i c e   % 1   h a s   o l d   o r   o u t - o f - d a t e   f i r m w a r e .  
 R e d u c e d   p e r f o r m a n c e   m a y   r e s u l t .  
 .  
  
 M e s s a g e I d = 2 7  
 S e v e r i t y = E r r o r  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ E R R _ D M A _ R E S O U R C E _ C O N F L I C T  
 L a n g u a g e = E n g l i s h  
 T h e   d e v i c e   c o u l d   n o t   a l l o c a t e   o n e   o r   m o r e   r e q u i r e d   r e s o u r c e s   d u e   t o   c o n f l i c t s  
 w i t h   o t h e r   d e v i c e s .   T h e   d e v i c e   D M A   s e t t i n g   o f   ' % 2 '   c o u l d   n o t   b e  
 s a t i s i f i e d   d u e   t o   a   c o n f l i c t   w i t h   D r i v e r   ' % 3 ' .  
 .  
  
 M e s s a g e I d = 2 8  
 S e v e r i t y = E r r o r  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ E R R _ I N T E R R U P T _ R E S O U R C E _ C O N F L I C T  
 L a n g u a g e = E n g l i s h  
 T h e   d e v i c e   c o u l d   n o t   a l l o c a t e   o n e   o r   m o r e   r e q u i r e d   r e s o u r c e s   d u e   t o   c o n f l i c t s  
 w i t h   o t h e r   d e v i c e s .   T h e   d e v i c e   i n t e r r u p t   s e t t i n g   o f   ' % 2 '   c o u l d   n o t   b e  
 s a t i s i f i e d   d u e   t o   a   c o n f l i c t   w i t h   D r i v e r   ' % 3 ' .  
 .  
  
 M e s s a g e I d = 2 9  
 S e v e r i t y = E r r o r  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ E R R _ M E M O R Y _ R E S O U R C E _ C O N F L I C T  
 L a n g u a g e = E n g l i s h  
 T h e   d e v i c e   c o u l d   n o t   a l l o c a t e   o n e   o r   m o r e   r e q u i r e d   r e s o u r c e s   d u e   t o   c o n f l i c t s  
 w i t h   o t h e r   d e v i c e s .   T h e   d e v i c e   m e m o r y   s e t t i n g   o f   ' % 2 '   c o u l d   n o t   b e  
 s a t i s i f i e d   d u e   t o   a   c o n f l i c t   w i t h   D r i v e r   ' % 3 ' .  
 .  
  
 M e s s a g e I d = 3 0  
 S e v e r i t y = E r r o r  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ E R R _ P O R T _ R E S O U R C E _ C O N F L I C T  
 L a n g u a g e = E n g l i s h  
 T h e   d e v i c e   c o u l d   n o t   a l l o c a t e   o n e   o r   m o r e   r e q u i r e d   r e s o u r c e s   d u e   t o   c o n f l i c t s  
 w i t h   o t h e r   d e v i c e s .   T h e   d e v i c e   p o r t   s e t t i n g   o f   ' % 2 '   c o u l d   n o t   b e  
 s a t i s i f i e d   d u e   t o   a   c o n f l i c t   w i t h   D r i v e r   ' % 3 ' .  
 .  
  
 M e s s a g e I d = 3 1  
 S e v e r i t y = E r r o r  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ B A D _ B L O C K _ W I T H _ N A M E  
 L a n g u a g e = E n g l i s h  
 T h e   f i l e   % 2   o n   d e v i c e   % 1   c o n t a i n s   a   b a d   d i s k   b l o c k .  
 .  
  
 M e s s a g e I d = 3 2  
 S e v e r i t y = W a r n i n g  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ W R I T E _ C A C H E _ E N A B L E D  
 L a n g u a g e = E n g l i s h  
 T h e   d r i v e r   d e t e c t e d   t h a t   t h e   d e v i c e   % 1   h a s   i t s   w r i t e   c a c h e   e n a b l e d .   D a t a   c o r r u p t i o n   m a y   o c c u r .  
 .  
  
 M e s s a g e I d = 3 3  
 S e v e r i t y = W a r n i n g  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ R E C O V E R E D _ V I A _ E C C  
 L a n g u a g e = E n g l i s h  
 D a t a   w a s   r e c o v e r e d   u s i n g   e r r o r   c o r r e c t i o n   c o d e   o n   d e v i c e   % 1 .  
 .  
  
 M e s s a g e I d = 3 4  
 S e v e r i t y = W a r n i n g  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ W R I T E _ C A C H E _ D I S A B L E D  
 L a n g u a g e = E n g l i s h  
 T h e   d r i v e r   d i s a b l e d   t h e   w r i t e   c a c h e   o n   d e v i c e   % 1 .  
 .  
  
 M e s s a g e I d = 3 6  
 S e v e r i t y = I n f o r m a t i o n a l  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ F I L E _ Q U O T A _ T H R E S H O L D  
 L a n g u a g e = E n g l i s h  
 A   u s e r   h i t   t h e i r   q u o t a   t h r e s h o l d   o n   v o l u m e   % 2 .  
 .  
  
 M e s s a g e I d = 3 7  
 S e v e r i t y = I n f o r m a t i o n a l  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ F I L E _ Q U O T A _ L I M I T  
 L a n g u a g e = E n g l i s h  
 A   u s e r   h i t   t h e i r   q u o t a   l i m i t   o n   v o l u m e   % 2 .  
 .  
  
 M e s s a g e I d = 3 8  
 S e v e r i t y = I n f o r m a t i o n a l  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ F I L E _ Q U O T A _ S T A R T E D  
 L a n g u a g e = E n g l i s h  
 T h e   s y s t e m   h a s   s t a r t e d   r e b u i l d i n g   t h e   u s e r   d i s k   q u o t a   i n f o r m a t i o n   o n  
 d e v i c e   % 1   w i t h   l a b e l   " % 2 " .  
 .  
  
 M e s s a g e I d = 3 9  
 S e v e r i t y = I n f o r m a t i o n a l  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ F I L E _ Q U O T A _ S U C C E E D E D  
 L a n g u a g e = E n g l i s h  
 T h e   s y s t e m   h a s   s u c c e s s f u l l y   r e b u i l t   t h e   u s e r   d i s k   q u o t a   i n f o r m a t i o n   o n  
 d e v i c e   % 1   w i t h   l a b e l   " % 2 " .  
 .  
  
 M e s s a g e I d = 4 0  
 S e v e r i t y = W a r n i n g  
 F a c i l i t y = I O  
 S y m b o l i c N a m e = I O _ F I L E _ Q U O T A _ F A I L E D  
 L a n g u a g e = E n g l i s h  
 T h e   s y s t e m   h a s   e n c o u n t e d   a n   e r r o r   r e b u i l d i n g   t h e   u s e r   d i s k   q u o t a  
 i n f o r m a t i o n   o n   d e v i c e   % 1   w i t h   l a b e l   " % 2 " .  
 .  
 