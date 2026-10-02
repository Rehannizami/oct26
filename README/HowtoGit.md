# How to Git: Cross-Platform Git & C++ Setup (GitHub Cloud)

## 1. Overview
- **Project:** `oct26`
- **Remote Cloud URL:** `https://github.com/Rehannizami/oct26.git`
- **Branch:** `main`
- **Machines:**
  - **Linux Machine:** Arch Linux (`~/workspace/oct26`)
  - **Windows Machine:** MSYS2 UCRT64 (`/home/softn/workspace/oct26` or your chosen path)

By using GitHub instead of a local network `git daemon`, both machines sync through the cloud. Neither machine needs to be left running, and both can push and pull from any network without IP dependency.

---

## 2. Linux Machine Setup (This Machine)

### Remote Configuration
The remote repository is already configured to point to GitHub:
```bash
cd ~/workspace/oct26
git remote set-url origin https://github.com/Rehannizami/oct26.git
```

Verify with:
```bash
git remote -v
```

### Pushing to GitHub (First Time Authentication)
When pushing over HTTPS, GitHub requires a **Personal Access Token (PAT)** instead of your GitHub password:

1. **Option A (GitHub CLI - Recommended):**
   ```bash
   sudo pacman -S github-cli
   gh auth login
   ```
   Choose `GitHub.com` -> `HTTPS` -> Log in with a web browser. Once authenticated, credentials are saved automatically.

2. **Option B (Personal Access Token):**
   - Go to GitHub -> **Settings** -> **Developer settings** -> **Personal access tokens** -> **Tokens (classic)**.
   - Generate a token with the `repo` scope.
   - Enable Git credential cache so you only enter it once:
     ```bash
     git config --global credential.helper cache
     ```
   - When running `git push -u origin main`, enter your GitHub username (`Rehannizami`) and paste your PAT as the password.

---

## 3. Windows Machine Setup (MSYS2 UCRT64)

### Step 1: Remove the Git Daemon from Boot
Previously, the Windows machine ran a local `git daemon` on startup. Since GitHub now hosts the repository, the daemon is no longer needed.

1. Open your MSYS2 UCRT64 terminal.
2. Edit `~/.bashrc`:
   ```bash
   nano ~/.bashrc
   ```
3. Locate the line that starts the git daemon (usually looks similar to):
   ```bash
   git daemon --reuseaddr --base-path=... --export-all ... &
   ```
4. Delete this line or comment it out by placing `#` at the beginning:
   ```bash
   # git daemon --reuseaddr ...
   ```
5. Save and exit (`Ctrl+O`, `Enter`, `Ctrl+X` in nano).
6. Stop any currently running Git daemon process:
   ```bash
   pkill git-daemon || killall git-daemon
   ```

### Step 2: Update Remote URL to GitHub
In your project directory on the Windows machine:
```bash
cd /path/to/oct26
git remote set-url origin https://github.com/Rehannizami/oct26.git
```

Verify:
```bash
git remote -v
```

### Step 3: Pull Latest Changes
```bash
git pull origin main
```

*(Note: On MSYS2/Windows, Git Credential Manager usually pops up a browser window to authenticate with GitHub automatically).*

---

## 4. Daily Workflow

### Before starting work (pull latest):
```bash
git pull origin main
```

### After making changes (commit and push):
```bash
git add .
git commit -m "Description of changes"
git push origin main
```

---

## 5. Cross-Platform C++ Build Instructions

### On Linux:
```bash
cd ~/workspace/oct26
cmake -B build -S .
cmake --build build
./build/oct26
```

### On Windows (MSYS2 UCRT64):
```bash
cmake -B build-ucrt64 -G "Ninja"
cmake --build build-ucrt64
./build-ucrt64/oct26.exe
```
