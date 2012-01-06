#include <QString>
#include <kconfigskeleton.h>
#include <framebookSettings.h>

FrameBookSettings::FrameBookSettings()
  : KConfigSkeleton()
{

      setCurrentGroup("Images");
      addItemString("user",user,"");
      addItemPassword("pass",pass,"");
}
