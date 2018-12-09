#pragma once

#include <QObject>
#include <QPointer>
#include <QString>

#include "globals.h"

namespace CleanEditor {
namespace Models {
  class AbstractEditorModel;
}

namespace Controllers {

class QML_EDITOR_EXPORT EditorController : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(EditorController)

public:
  explicit EditorController(QObject* parent = nullptr);

  //Takes ownership of model
  void setModel(CleanEditor::Models::AbstractEditorModel* model);

  QString text() const;
  void setText(const QString& text);

  int id() const;
  void setId(int id);

Q_SIGNALS:
  void textChanged();

private:
  QPointer<CleanEditor::Models::AbstractEditorModel> model_;
  QMetaObject::Connection text_changed_connection_;
};

} // namespace Controllers
} // namespace CleanEditor