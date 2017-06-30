Binary search implemation with iterative and recursive ways.
--

Code below may causes integer overflow
  
      mid = (Start + end) / 2;

To avoid overflow calculate mid position like this
    
      mid = start + ( (end - start) / 2 );
