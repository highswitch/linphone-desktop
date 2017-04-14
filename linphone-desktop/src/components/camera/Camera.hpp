/*
 * Camera.hpp
 * Copyright (C) 2017  Belledonne Communications, Grenoble, France
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 *  Created on: February 2, 2017
 *      Author: Ronan Abhamon
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include <memory>

#include <QOpenGLFramebufferObject>
#include <QQuickFramebufferObject>

// =============================================================================

class CallModel;
class Camera;
struct ContextInfo;

namespace linphone {
  class Call;
}

class CameraRenderer : public QQuickFramebufferObject::Renderer {
  friend class Camera;

public:
  CameraRenderer ();
  ~CameraRenderer ();

protected:
  QOpenGLFramebufferObject *createFramebufferObject (const QSize &size) override;
  void render () override;
  void synchronize (QQuickFramebufferObject *item) override;

private:
  void updateWindowId ();

  ContextInfo *mContextInfo;
  bool mUpdateContextInfo = false;

  bool mIsPreview = false;
  std::shared_ptr<linphone::Call> mLinphoneCall;

  QQuickWindow *mWindow;
};

// -----------------------------------------------------------------------------

class Camera : public QQuickFramebufferObject {
  friend class CameraRenderer;

  Q_OBJECT;

  Q_PROPERTY(CallModel * call READ getCall WRITE setCall NOTIFY callChanged);
  Q_PROPERTY(bool isPreview READ getIsPreview WRITE setIsPreview NOTIFY isPreviewChanged);

public:
  Camera (QQuickItem *parent = Q_NULLPTR);
  ~Camera () = default;

  QQuickFramebufferObject::Renderer *createRenderer () const override;

signals:
  void callChanged (CallModel *call);
  void isPreviewChanged (bool isPreview);

private:
  CallModel *getCall () const;
  void setCall (CallModel *call);

  bool getIsPreview () const;
  void setIsPreview (bool status);

  bool mIsPreview = false;
  CallModel *mCall = nullptr;

  QTimer *mRefreshTimer;
};

#endif // CAMERA_H_
