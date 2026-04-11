# AGENTS.md - QMK Firmware Agent Guide

This file gives coding agents practical rules for working in this repo.

## Sources Used

- `Makefile`
- `docs/unit_testing.md`
- `docs/cli_commands.md`
- `docs/coding_conventions_c.md`
- `docs/coding_conventions_python.md`
- `docs/pr_checklist.md`
- `.editorconfig`
- `.clang-format`
- `.github/copilot-instructions.md`

## Setup and Environment

- Ensure submodules are ready:
  - `qmk git-submodule`
  - or `make git-submodule`
- Install dev deps:
  - `python3 -m pip install -r requirements-dev.txt`
- `make` expects a working `qmk` CLI (`qmk hello`).
- CI commonly uses container `ghcr.io/qmk/qmk_cli`.

## Build Commands

- Compile firmware (preferred):
  - `qmk compile -kb <keyboard> -km <keymap>`
- Equivalent make form:
  - `make <keyboard>:<keymap>`
- Flash firmware:
  - `qmk flash -kb <keyboard> -km <keymap>`
  - `make <keyboard>:<keymap>:flash`
- Discover targets:
  - `qmk list-keyboards`
  - `qmk list-keymaps -kb <keyboard>`
  - `make <keyboard>:list-keymaps`

## Test Commands

### C Tests

- Run all C tests:
  - `qmk test-c`
  - `make test:all`
- List tests:
  - `qmk test-c --list`
  - `make list-tests`
- Run one C test:
  - `qmk test-c --test basic`
- Run pattern:
  - `qmk test-c --test "unicode*"`
- make substring filtering:
  - `make test:tap_hold_configurations`
  - `make test:retro_shift:tap_hold_configurations`
- Clean before test:
  - `qmk test-c --clean`
- C test binaries are in `.build/test/`.

### Python Tests

- Run all:
  - `qmk pytest`
- Run one module:
  - `qmk pytest -t qmk.tests.test_cli_commands`
- Run one test case:
  - `qmk pytest -t qmk.tests.test_cli_commands.test_c2json`

### Debugging

- Enable debug logs for make-driven C tests:
  - `make test:all DEBUG=1`

## Lint and Formatting

- Python format:
  - `qmk format-python`
- C format:
  - `qmk format-c --core-only <files...>`
  - `qmk format-c --core-only -a`
- Text format:
  - `qmk format-text <files...>`
- Keyboard lint:
  - `qmk lint --strict --keyboard <keyboard>`
  - `qmk info -l --keyboard <keyboard>`
- Dockerized parity targets:
  - `make format-core`
  - `make pytest`
  - `make format-and-pytest`

## Style Rules

### Global

- Match surrounding code style first.
- Keep changes minimal and focused.
- Respect `.editorconfig`:
  - default: spaces, 4-space indent, LF, UTF-8
  - YAML: 2-space indent
  - Makefiles: tabs for recipe lines

### C

- Follow `docs/coding_conventions_c.md` and `.clang-format`.
- 4-space indentation, brace-on-same-line style.
- Always include optional braces for control statements.
- Use `#pragma once` in headers.
- Prefer QMK abstractions over low-level hardware access.
- Timing APIs:
  - use `wait_ms()` not `_delay_ms()`
  - use `timer_read()` / `timer_read32()` APIs
- Do not sort includes just for style (`SortIncludes: false`).

### Python

- Target Python 3.9 compatibility.
- Follow `docs/coding_conventions_python.md`.
- 4-space indentation; one statement per line.
- Imports:
  - no `from x import *`
  - group stdlib / third-party / local
  - avoid ambiguous aliasing
- Naming:
  - `snake_case` for funcs/vars/modules
  - `PascalCase` for classes
  - `UPPER_SNAKE_CASE` for constants
- Add meaningful docstrings for functions.
- Avoid broad exception handling; keep try/except tight.

### QMK Keyboard/Keymap

- In keymaps, prefer `#include QMK_KEYBOARD_H`.
- Custom keycode enum should start at `QK_USER`.
- Keep `keymaps/default` pristine/minimal.
- Do not enable VIA in default keymaps in this repo.
- Move layout/config data to `info.json`/`keyboard.json` where possible.

## Naming, Licensing, and Metadata

- New files/directories should be lowercase (except justified upstream cases).
- C/H files should include GPL-compatible license headers (SPDX preferred).
- Format JSON metadata before submit:
  - `qmk format-json -i <path/to/info.json>`
  - `qmk format-json -i <path/to/keyboard.json>`
- Validate keyboard metadata:
  - `qmk lint -kb <keyboard>`

## Copilot and Cursor Rules

- Copilot rules file exists: `.github/copilot-instructions.md`.
- No `.cursorrules` found.
- No `.cursor/rules/` directory found.

Important Copilot guidance to honor:

- New keyboard additions target `master`.
- Most updates/refactors/core changes target `develop`.
- Keep PRs scoped to one coherent change.
- Prefer `#pragma once`, `wait_ms()`, and timer abstractions.
- Enforce lowercase naming and proper licensing.
- Run lint/format/validation for touched areas.

Note: `.github/copilot-instructions.md` is review-oriented and includes
`excludeAgent: ["coding-agent"]`; still follow the technical standards above.

## Agent Workflow

- Before edits: inspect nearby code for local conventions.
- After edits: run the smallest relevant test first (single test when possible).
- If core behavior changes: run broader suite (`qmk test-c`, `qmk pytest` as needed).
- Run relevant formatter/lint checks on touched files.
- Report what was run, what passed, and what was not verified.
