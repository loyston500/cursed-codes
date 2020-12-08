local function is(condition)
  local flag
  ::ifTrue::
  while flag do
    return true
  end

  while condition do
    flag = true
    goto ifTrue
  end

  return false
end

local function Statement(condition, in1, in2)
  while is(condition) do
    return in1
  end
  while is(not condition) do
    return in2
  end
end

local function funIf(condition, fn1, fn2)
  for i = 1, Statement(condition, 2, 0) do
    return fn1()
  end
  fn2()
end

funIf(true, function()
  print "fun"
end,
function()
  print "no fun"
end)
