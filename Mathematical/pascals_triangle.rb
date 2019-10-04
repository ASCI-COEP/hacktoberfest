def pascals_triangle(n)
  (0..n).each{|r|
          list=[1]
          term=1
          k=1
          (0..r-1).step(1){|index|
                  term=term*(r-k+1)/k
                  list.push term 
                  k+=1
          }
          p list
  }
end

#Output
# pascals_triangle(4)
# [1]
# [1, 1]
# [1, 2, 1]
# [1, 3, 3, 1]
# [1, 4, 6, 4, 1]