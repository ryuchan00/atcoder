_, m = gets.split.map(&:to_i)
a = gets.split.map(&:to_i)
while m > 0
  i = a.index(a.max)
  tmp_a = a.clone
  tmp_a.delete(a.max)
  second_max = tmp_a.max
  while m > 0 && a[i] > second_max
    a[i] = (a[i] / 2).floor
    m -= 1
  end
end
puts a.inject(:+)