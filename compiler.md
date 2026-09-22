# How to Install and Use GCC/GDB on Windows (via MSYS2)

Follow these steps to install a modern C/C++ compiler toolchain (including `gcc`, `g++`, `gdb`, and `make`) on Windows and get it running in Visual Studio Code.

---

### 1. Install MSYS2
1. Download and run the installer from the official website: [msys2.org](https://msys2.org)
2. Follow the setup wizard and leave the installation folder as the default (`C:\msys64`).

### 2. Install the Compiler & Debugger Toolchain
1. Open the **MSYS2 UCRT64** terminal from your Windows Start Menu.
2. Type or paste the following command and press **Enter**:
   ```bash
   pacman -S mingw-w64-ucrt-x86_64-toolchain
   ```
3. Press **Enter** again when prompted to install all packages in the group, and type **Y** to confirm the installation.

### 3. Add to Windows Environment Variables (Path)
To use the compiler from any standard Windows Command Prompt or PowerShell window:
1. Press the **Windows Key**, type `env`, and select **Edit the system environment variables**.
2. Click the **Environment Variables...** button at the bottom right.
3. Under *User variables* (or *System variables*), find and select **Path**, then click **Edit...**.
4. Click **New** and paste this exact path: `C:\msys64\ucrt64\bin`
5. Click **OK** on all windows to save and exit.

### 4. Verify the Installation
Open a completely **new** Windows Command Prompt (`cmd`) or PowerShell window and run these commands to confirm everything works:
```bash
gcc --version
gdb --version
```
If both commands display version numbers, the installation is successful!

### 5. Running a Sample C++ File in Visual Studio Code
1. Open **Visual Studio Code**.
2. Go to `File` > `Open Folder...` and select or create an empty directory for your C++ project.
3. Install the official **C/C++** extension by Microsoft from the Extensions view (`Ctrl+Shift+X`).
4. Create a new file in your folder, name it `main.cpp`, and paste your C++ code into it.
5. With `main.cpp` open, click the **Play icon (Run C/C++ File)** in the top right corner of the editor.
6. Select **C/C++: g++.exe build and run active file** from the drop-down menu to compile and run your code.

### 6. Next Steps: Setting up the Debugger
To configure advanced debugging profiles (such as multifile builds or custom `launch.json` and `tasks.json` settings), follow along with this step-by-step video guide:
* **Watch Tutorial:** [How to configure C/C++ debugger in VSCode](https://www.youtube.com/watch?v=fxnWT7tqXho)
