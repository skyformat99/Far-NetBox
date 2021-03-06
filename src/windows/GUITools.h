#pragma once

#include <Classes.hpp>
#include <FileMasks.H>

// from shlobj.h
#define CSIDL_DESKTOP                   0x0000        // <desktop>
#define CSIDL_SENDTO                    0x0009        // <user name>\SendTo
#define CSIDL_DESKTOPDIRECTORY          0x0010        // <user name>\Desktop
#define CSIDL_COMMON_DESKTOPDIRECTORY   0x0019        // All Users\Desktop
#define CSIDL_APPDATA                   0x001a        // <user name>\Application Data
#define CSIDL_PROGRAM_FILES             0x0026        // C:\Program Files
#define CSIDL_PERSONAL                  0x0005        // My Documents

class TSessionData;

typedef nb::FastDelegate0<void> TProcessMessagesEvent;

NB_CORE_EXPORT bool FindFile(UnicodeString & APath);
NB_CORE_EXPORT bool FindTool(const UnicodeString & Name, UnicodeString & APath);
NB_CORE_EXPORT bool FileExistsEx(const UnicodeString & APath);
NB_CORE_EXPORT bool ExecuteShell(const UnicodeString & APath, const UnicodeString & AParams, bool ChangeWorkingDirectory = false);
NB_CORE_EXPORT bool ExecuteShell(const UnicodeString & Command);
NB_CORE_EXPORT bool ExecuteShell(const UnicodeString & APath, const UnicodeString & AParams,
  HANDLE & Handle);
NB_CORE_EXPORT bool ExecuteShellAndWait(HINSTANCE Handle, const UnicodeString & APath,
  const UnicodeString & Params, TProcessMessagesEvent ProcessMessages);
NB_CORE_EXPORT bool ExecuteShellAndWait(HINSTANCE Handle, const UnicodeString & Command,
  TProcessMessagesEvent ProcessMessages);
NB_CORE_EXPORT void OpenSessionInPutty(const UnicodeString & PuttyPath,
  TSessionData * SessionData);
NB_CORE_EXPORT bool SpecialFolderLocation(int PathID, UnicodeString & APath);
NB_CORE_EXPORT UnicodeString GetPersonalFolder();
NB_CORE_EXPORT UnicodeString ItemsFormatString(const UnicodeString & SingleItemFormat,
  const UnicodeString & MultiItemsFormat, intptr_t Count, const UnicodeString & FirstItem);
NB_CORE_EXPORT UnicodeString ItemsFormatString(const UnicodeString & SingleItemFormat,
  const UnicodeString & MultiItemsFormat, const TStrings * Items);
NB_CORE_EXPORT UnicodeString FileNameFormatString(const UnicodeString & SingleFileFormat,
  const UnicodeString & MultiFilesFormat, const TStrings * AFiles, bool Remote);
NB_CORE_EXPORT UnicodeString UniqTempDir(const UnicodeString & BaseDir,
  const UnicodeString & Identity, bool Mask = false);
NB_CORE_EXPORT bool DeleteDirectory(const UnicodeString & ADirName);
NB_CORE_EXPORT UnicodeString FormatDateTimeSpan(const UnicodeString & TimeFormat, const TDateTime & DateTime);

class NB_CORE_EXPORT TLocalCustomCommand : public TFileCustomCommand
{
public:
  TLocalCustomCommand();
  explicit TLocalCustomCommand(
    const TCustomCommandData & Data, const UnicodeString & RemotePath, const UnicodeString & LocalPath);
  explicit TLocalCustomCommand(
    const TCustomCommandData & Data, const UnicodeString & RemotePath, const UnicodeString & LocalPath,
    const UnicodeString & AFileName, const UnicodeString & LocalFileName,
    const UnicodeString & FileList);
  virtual ~TLocalCustomCommand() {}

  virtual bool IsFileCommand(const UnicodeString & Command) const;
  bool HasLocalFileName(const UnicodeString & Command) const;

protected:
  virtual intptr_t PatternLen(const UnicodeString & Command, intptr_t Index) const;
  virtual bool PatternReplacement(intptr_t Index, const UnicodeString & Pattern,
    UnicodeString & Replacement, bool & Delimit) const;
  virtual void DelimitReplacement(UnicodeString & Replacement, wchar_t Quote);

private:
  UnicodeString FLocalPath;
  UnicodeString FLocalFileName;
};

#if 0
void ValidateMaskEdit(TFarComboBox * Edit);
void ValidateMaskEdit(TFarEdit * Edit);
#endif

#define PageantTool L"pageant.exe"
#define PuttygenTool L"puttygen.exe"

