n, k = gets.split.map(&:to_i)
s = gets.to_s.chars
a = 0
s.each_with_index do |v,i|
  if s[i] == 'L'
    a += 1 if !i.zero? && s[i] == s[i -1]
  else
    a += 1 if !s[i + 1].nil? && s[i] == s[i +-1]
  end
end
if k.odd?
  tmp_a = 0
  a < tmp_a
end