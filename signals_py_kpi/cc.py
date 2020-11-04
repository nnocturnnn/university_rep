
class Point: 
  def gatherAttrs(self):        
    attrs = []        
    for key in sorted(self.__dict__):            
        attrs.append('%s' % getattr(self, key))        
    return ', '.join(attrs)
  def __repr__(self):        
    return '[%s: %s]' % (self.__class__.__name__, self.gatherAttrs())

class ObjCounter(Point): 
    count = 0        
    def __init__(self):            
        self.attr1 = ObjCounter.count            
        self.attr2 = ObjCounter.count+1            
        ObjCounter.count += 2

Y = ObjCounter()                         
print(Y)        