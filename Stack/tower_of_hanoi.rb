# A recursive ruby method to solve the tower of hanoi problem

def tower_of_hanoi(disk, source, starting_point, destination)
  if disk == 1
    puts "#{source} -> #{destination}"
    return
  end
  tower_of_hanoi(disk - 1, source, destination, starting_point)
  puts "#{source} -> #{destination}"
  tower_of_hanoi(disk - 1, starting_point, source, destination)
  nil
end

#tower_of_hanoi(3, 'source','aux','dest')
#Output:
# source -> dest
# source -> aux
# dest -> aux
# source -> dest
# aux -> source
# aux -> dest
# source -> dest
