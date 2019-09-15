odd = true
even = true
gets.chomp.chars.each_with_index do |v, i|
  break unless odd || even
  if (i + 1).odd?
    odd = false unless v =~ /(R|U|D)/
  elsif (i + 1).even?
  even = false unless v =~ /(L|U|D)/
  end
end
puts (odd && even) ? 'Yes' : 'No'