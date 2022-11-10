   def removeDuplicates(self, s: str) -> str:
       print(s)
       dup = set([])
       for i in s:
           print("====", dup)
           if i in dup:
               dup.remove(i)
               print(i)
           else:
               dup.add(i)
       print("====", dup)
       return ''.join(dup)
