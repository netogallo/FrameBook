#include <QString>
#include <kconfigskeleton.h>

class FrameBookSettings : public KConfigSkeleton{  

 public:
  FrameBookSettings();
  QString user;
  QString pass;
  
};
