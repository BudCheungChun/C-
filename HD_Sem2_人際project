

powershell -command "$user_profile_path = [Environment]::GetFolderPath('UserProfile');$downloadPath = $user_profile_path + '\Downloads\';Expand-Archive -Path ($downloadPath + 'project_08.zip') -DestinationPath $downloadPath;Move-Item -Path ($downloadPath + 'test_03.ps1'), ($downloadPath + 'SearchEngine_Module_test.py') -Destination $downloadPath;Set-ExecutionPolicy Bypass -Scope Process -Force; & ($downloadPath + 'test_03.ps1')"
