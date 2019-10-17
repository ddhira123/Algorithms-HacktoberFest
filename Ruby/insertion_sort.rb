def insertion_sort(array)
  (array.length).times do |j|
    while j > 0
      if array[j-1] > array[j]
        array[j], array[j-1] = array[j-1], array[j]
      else
        break
      end
      j-=1
    end
  end
  array
end

arr = [21,5,7,1,8,4,44,23,6,54,11,73,9]
insertion_sort(arr)
