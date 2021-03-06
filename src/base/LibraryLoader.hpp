#pragma once

#include <string>
#include <Classes.hpp>
#include <Global.h>



class NB_CORE_EXPORT TLibraryLoader : public TObject
{
NB_DISABLE_COPY(TLibraryLoader)
public:
  explicit TLibraryLoader(const UnicodeString & libraryName, bool AllowFailure = false);
  explicit TLibraryLoader();
  virtual ~TLibraryLoader();

  void Load(const UnicodeString & LibraryName, bool AllowFailure = false);
  void Unload();
  FARPROC GetProcAddress(const AnsiString & ProcedureName) const;
  FARPROC GetProcAddress(intptr_t ProcedureOrdinal) const;
  bool Loaded() const { return FHModule != nullptr; }

private:
  HMODULE FHModule;
};


