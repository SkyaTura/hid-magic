require 'nvim_utils'

-- Local Variables
local insertMode = false
local commandMode = false

-- Helper Constants
local colemak_modes = {
  i = true,
  ic = true,
  ix = true,
  R = true,
  Rc = true,
  Rv = true,
  Rx = true,
  c = true,
}
local valid_layouts = {
  [0] = true,
  [1] = true,
}
local colemak_events = {
  FocusLost = true,
  VimLeave = true,
}
local qwerty_events = {
  VimEnter = true,
}
local auto_events = {
  InsertEnter = true,
  InsertLeave = true,
  FocusGained = true,
  CmdlineEnter = true,
  CmdlineLeave = true,
  CmdwinEnter = true,
  CmdwinLeave = true,
  CompleteDone = true,
}

-- Global function to get current mode
function getPseudoMode()
  if insertMode == true then
    return 'i'
  elseif commandMode == true then
    return 'c'
  else
    return 'n'
  end
end

-- xkbswitch wapper
function setSystemKeyboardLayout(layout)
  os.execute('xkbswitch -s ' .. layout)
end

-- Event Listener
function kbdModeChange(name, action)
  local event = name .. action
  local layout = 0

  if colemak_events[event] then
    layout = 0
  elseif qwerty_events[event] then
    layout = 1
  else
    if event == "InsertEnter" then
      insertMode = true
    elseif event == "InsertLeave" then
      insertMode = false
    elseif event == "CmdlineEnter" or event == "CmdwinEnter" then
      commandMode = true
    elseif event == "CmdlineLeave" or event == "CmdwinLeave" then
      commandMode = false
    end

    if insertMode == true or commandMode == true then
      layout = 0
    else
      layout = 1
    end
  end

  if valid_layouts[layout] then
    setSystemKeyboardLayout(layout)
  end

  local mode = vim.api.nvim_get_mode()
end

nvim_create_augroups({
  keyboard_layout_switcher = {
    -- Vim Events
    { 'VimEnter',     '*', 'lua kbdModeChange("Vim",      "Enter" )' },
    { 'VimLeave',     '*', 'lua kbdModeChange("Vim",      "Leave" )' },
    { 'FocusGained',  '*', 'lua kbdModeChange("Focus",    "Gained")' },
    { 'FocusLost',    '*', 'lua kbdModeChange("Focus",    "Lost"  )' },

    -- Mode Events
    { 'InsertEnter',  '*', 'lua kbdModeChange("Insert",   "Enter" )' },
    { 'InsertLeave',  '*', 'lua kbdModeChange("Insert",   "Leave" )' },
    { 'CmdlineLeave', '*', 'lua kbdModeChange("Cmdline",  "Leave" )' },
    { 'CmdlineEnter', '*', 'lua kbdModeChange("Cmdline",  "Enter" )' },
    { 'CmdwinLeave',  '*', 'lua kbdModeChange("Cmdwin",   "Leave" )' },
    { 'CmdwinEnter',  '*', 'lua kbdModeChange("Cmdwin",   "Enter" )' },
    { 'CompleteDone', '*', 'lua kbdModeChange("Complete", "Done"  )' },
  }
})
